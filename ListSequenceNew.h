#pragma once

#include "SequenceNew.h"
#include "LinkedListNew.h"
#include "DynamicArrayNew.h"
template<class T>

class ListSequence : public Sequence<T> {
    private:
        LinkedList<T>* list;

    public:
        ListSequence(T* items, int count) {
            list = new LinkedList<T>(items, count);
        }
        ListSequence() {
            list = new LinkedList<T>();
        }

        ListSequence(const LinkedList<T>& other) {
            list = new LinkedList<T>(other);
        }

        ListSequence(const ListSequence<T>& other) {
            list = new LinkedList<T>(*other.list);
        }

        ~ListSequence() {
            delete list;
        }

        T GetFirst() const override {
            return list->GetFirst();
        }

        T GetLast() const override {
            return list->GetLast();
        }

        T Get(int index) const override {
            return list->Get(index);
        }

        int GetLength() const override {
            return list->GetLength();
        }

        Sequence<T>* Append(T item) override {
            return Instance()->AppendInternal(item);
        }

        Sequence<T>* Prepend(T item) override {
            return Instance()->PrependInternal(item);
        }

        Sequence<T>* InsertAt(T item, int index) override {
            if (index < 0 || index > list->GetLength())
                throw std::out_of_range("Index out of range");
            return Instance()->InsertAtInternal(item, index);
        }

        Sequence<T>* Concat(Sequence<T>* other) override {
            if (!other)
                throw std::invalid_argument("Other sequence is null");
            return Instance()->ConcatInternal(other);
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
            if (startIndex < 0 || endIndex >= list->GetLength() || startIndex > endIndex)
                throw std::out_of_range("Invalid indices");


            return Instance()->GetSubsequenceInternal(startIndex, endIndex);
        }

        Sequence<T>* Map(T (*func)(T)) override {

            return Instance()->MapInternal(func);
        }

        T Reduce(T (*func)(T, T), T init) override {
            T result = init;
            for (int i = 0; i < list->GetLength(); i++) {
                result = func(result, list->Get(i));
            }
            return result;
        }

        Sequence<T>* Where(bool (*predicate)(T)) override {

            return Instance()->WhereInternal(predicate);
        }
    virtual ListSequence<T>* Instance()= 0;
    virtual ListSequence<T>* Clone()const = 0;

    protected:
    ListSequence<T>* AppendInternal(T item) {
        list->Append(item);
        return this;
    }
    ListSequence<T>* PrependInternal(T item) {
        list->Prepend(item);
        return this;
    }
    ListSequence<T>* InsertAtInternal(T item, int index) {
        list->InsertAt(item, index);
        return this;
    }
    ListSequence<T>* ConcatInternal(Sequence<T>* other) {
        for (int i = 0; i < other->GetLength(); i++) {
            list->Append(other->Get(i));
        }
        return this;
    }
    ListSequence<T>* GetSubsequenceInternal(int startIndex, int endIndex) {
        ListSequence<T>* sub= new LinkedList<T>();
        for (int i = startIndex; i <= endIndex; i++) {
            sub->Append(list->Get(i));
        }
        return sub;
    }
    ListSequence<T>* MapInternal(T (*func)(T)) {
        ListSequence<T>* result = new LinkedList<T>();
        for (int i = 0; i < list->GetLength(); i++) {
           result->Append(func(list->Get(i)));
        }
        return result;
    }
    ListSequence<T>* WhereInternal(bool (*predicate)(T)) {
        ListSequence<T>* result = new LinkedList<T>();
        for (int i = 0; i < list->GetLength(); i++) {
            T item = list->Get(i);
            if (predicate(item)) {

            }
        }
        return result;
    }
};


