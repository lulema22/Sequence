#ifndef ZIP_UNZIP_H
#define ZIP_UNZIP_H
#include "MutableArray.h"

template<typename T1, typename T2>
        static Sequence<std::pair<T1, T2>>* Zip(const Sequence<T1>* seq1, const Sequence<T2>* seq2){
    int len = std::min(seq1->GetLength(), seq2->GetLength());
    auto result = new MutableArraySequence<std::pair<T1, T2>>();

    for (int i = 0; i < len; i++){
        std::pair<T1, T2> p(seq1->Get(i), seq2->Get(i));
        result ->Append(p);
    }
    return result;
}

template<typename T1, typename T2>

static void Unzip(const Sequence<std::pair<T1, T2>>* zipP, Sequence<T1>*& seq1, Sequence<T2>*& seq2){
    //ссылки на указатель
    int len = zipP->GetLength();
    seq1 = new MutableArraySequence<T1>();
    seq2 = new MutableArraySequence<T2>();
    for (int i = 0; i <len; i++){
        std::pair<T1, T2> p = zipP->Get(i);
        seq1->Append(p.first);
        seq2->Append(p.second);
    }

}


#endif //ZIP_UNZIP_H