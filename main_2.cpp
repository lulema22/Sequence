#include <iostream>
#include "Person.h"
#include "MutableImmutableDek.h"

int add(int a, int b) { return a + b; }
int square(int x) { return x * x; }

template<class T>
class DebugMutableDeck : public MutableDeck<T> {
public:
    using MutableDeck<T>::MutableDeck;
    int getSegmentCount() const { return this->segmentArray.GetLength(); }
    void printSegments() const {
        std::cout << "Сегменты :";
        for (int s = 0; s < getSegmentCount(); ++s) {
            std::cout << " [";
            for (int i = 0; i < this->segmentCapacity; ++i) {
                std::cout << this->segmentArray.Get(s)->Get(i)
                          << (i + 1 < this->segmentCapacity ? " " : "");
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }

};

template<class T>
class DebugImmutableDeck : public ImmutableDeck<T> {
public:
    using ImmutableDeck<T>::ImmutableDeck;
    int getSegmentCount() const { return this->segmentArray.GetLength(); }
    void printSegments() const {
        std::cout << "Сегменты:";
        for (int s = 0; s < getSegmentCount(); ++s) {
            std::cout << " [";
            for (int i = 0; i < this->segmentCapacity; ++i) {
                std::cout << this->segmentArray.Get(s)->Get(i)
                          << (i + 1 < this->segmentCapacity ? " " : "");
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }

};


void printDeck(const SegmentDek<int>& d, const std::string& title) {
    std::cout << title;
    for (int i = 0; i < d.GetLength(); ++i) {
        std::cout << d.Get(i) << (i + 1 < d.GetLength() ? " " : "");
    }
    std::cout << std::endl;
}

void printPersonDeck(const SegmentDek<Person>& d, const std::string& title) {
    std::cout << title;
    for (int i = 0; i < d.GetLength(); ++i) {
        const Person& p = d.Get(i);
        PersonID id = p.GetID();
        time_t bd = p.GetBirthDate();
        std::tm* bt = std::localtime(&bd);

        char buf[32];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d", bt);

        std::cout<< p.GetLastName() << " "<< p.GetFirstName() << " ("<< id.series << ":" << id.number << "), "<< buf<< (i + 1 < d.GetLength() ? "; " : "");
    }
    std::cout << std::endl;
}


int main() {
    std::cout << "(MutableDeck<int>)" << std::endl;
    DebugMutableDeck<int> md;


    for (int i = 1; i <= 5; ++i) md.Append(i);
    printDeck(md, "начальный:     ");
    md.printSegments();

    md.InsertAt(99, 1);  // вставка в начало
    printDeck(md, "после InsertAt(99, 2):");
    md.printSegments();



    md.Map(square);
    printDeck(md, "после Map (квадрат):");
    md.printSegments();

    int sum_md = md.Reduce(add, 0);
    std::cout << "сумма через Reduce: " << sum_md << std::endl;

    DebugMutableDeck<int> md_unsort;
    md_unsort.Append(3)->Append(1)->Append(2);
    printDeck(md_unsort, "до сортировки:");
    md_unsort.printSegments();
    md_unsort.Sort();
    printDeck(md_unsort, "после сортировки:");
    md_unsort.printSegments();

    DebugMutableDeck<int> md2;
    md2.Append(10)->Append(20);
    md2.Concat(&md_unsort);
    printDeck(md2, "после Concat:");
    md2.printSegments();


    std::cout << std::endl;
    std::cout << "(ImmutableDeck<int>)" << std::endl;
    DebugImmutableDeck<int> imd;


    auto* imdBase = imd.Clone();
    for (int i = 1; i <= 5; ++i) imdBase = imdBase->Append(i);
    printDeck(*imdBase, "начальный:  ");
    if (auto* di = dynamic_cast<DebugImmutableDeck<int>*>(imdBase)) di->printSegments();

    auto* imd1 = imdBase->InsertAt(88, 0); // вставка в начало
    printDeck(*imd1, "после InsertAt(88, 0):");
    if (auto* di = dynamic_cast<DebugImmutableDeck<int>*>(imd1)) di->printSegments();

    auto* mapBranch = imd1->Map(square);
    printDeck(*mapBranch, "после Map (квадрат):");
    if (auto* di = dynamic_cast<DebugImmutableDeck<int>*>(mapBranch)) di->printSegments();

    int sum_branch = imd1->Reduce(add, 0);
    std::cout << "сумма через Reduce: " << sum_branch << std::endl;

    auto* sortBranch = imd1->Sort();
    printDeck(*sortBranch, "после сортировки:");
    if (auto* di = dynamic_cast<DebugImmutableDeck<int>*>(sortBranch)) di->printSegments();



    std::cout << std::endl;
    std::cout << "(MutableDeck<Person>)" << std::endl;
    DebugMutableDeck<Person> pd;

    Person p1({1, 234}, "Катек",  "Федоровская",   "A. ",  std::time(nullptr) - 100000000);
    Person p2({5, 678}, "Илюха",  "Одинцов",  "А. ", std::time(nullptr) - 200000000);

    pd.Append(p1);
    pd.Append(p2);
    printPersonDeck(pd, "до вставки: ");

    Person p3({3, 333}, "Никитос", "Якименко", "А. ", std::time(nullptr) - 150000000);
    pd.InsertAt(p3, 1);
    printPersonDeck(pd, "после InsertAt: ");




    delete mapBranch;
    delete sortBranch;
    delete imd1;
    delete imdBase;
    return 0;
}
