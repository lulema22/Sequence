#ifndef MUTABLE_LIST_H
#define MUTABLE_LIST_H

#include "ListSequenceNew.h"

template <class T>
class MutableListSequence : public ListSequence<T>{

public:
    using ListSequence<T>::ListSequence;

    virtual ListSequence<T>* Instance() override {
        return this;
    }
    virtual ListSequence<T>* Clone() const override {
        return new MutableListSequence<T>(*this);
    }


};

template <class T>
class ImmutableListSequence : public ListSequence<T> {
public:
    using ListSequence<T>::ListSequence;
    
    virtual ListSequence<T>* Instance() override {
        return this->Clone();
    }
    virtual ListSequence<T>* Clone() const override {
        return new ImmutableListSequence<T>(*this);
    }
};

#endif // MUTABLE_LIST_H