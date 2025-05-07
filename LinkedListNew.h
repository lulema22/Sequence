#ifndef LINKED_LIST_NEW_H
#define LINKED_LIST_NEW_H
#include <iostream>
template <class T>
class LinkedList {

private: 
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    int length;
 
public:

    LinkedList(T* elem, int length) : head(nullptr), length(0){
        for (int i = length - 1; i>=0; --i){
            Prepend(elem[i]);
        }
    }
    LinkedList() : head(nullptr), length(0){}

    LinkedList( const LinkedList<T>& linkedList) : head(nullptr), length(0){
        Node* current = linkedList.head;
        while (current){
            Append(current -> data);
            current = current -> next;
        }
    }
    ~LinkedList(){
        while(head){
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
        head = nullptr;
        length = 0;
    }

    T GetFirst(){
        if (length == 0){
            throw std::out_of_range("Out of range");
        }
        return(head->data);
    }
    T GetLast(){
        
        if (length == 0) {
            throw std::out_of_range("Out of range");
        }
        Node* current = head;
        while (current -> next){
            current = current -> next;
        }
        return current->data;
    }
    T Get (int index){
        if (index <0 || index >= length){
            throw std::out_of_range("Out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        return current -> data;
    }
    int GetLength(){
        return length;
    }
    void Append(T elem){
        Node* newNode = new Node(elem);
        if (!head){
            head = newNode;
        } else{
            Node* current = head;
            while(current -> next){
                current = current -> next;
            }
            current->next = newNode;
        }
        length++;
    }
    void Prepend(T elem){
        Node* newNode = new Node(elem);
        newNode -> next = head;
        head = newNode;
        length++;
    }
    void InsertAt(T elem, int index){
        //IndexOutOfRange (если индекс отрицательный или больше/равен числу элементов)
        if( index < 0 || index >= length){
            throw std::out_of_range("Out of range");
        }
        if (index == 0){
            Prepend(elem);
        } else {
            Node* newNode = new Node(elem);
            Node* current = head;
            for (int i = 0; i < index-1; i++){
                current = current -> next;
            }
            newNode -> next = current -> next;
            current-> next = newNode;
            length++;
        }
    }
     LinkedList<T>* GetPartList(int startIndex, int endIndex) {
        //IndexOutOfRange (если хотя бы один из индексов отрицательный или больше/равен числу элементов)
        if(startIndex == 0 || endIndex == 0 || startIndex >= length || endIndex >= length){
            throw std::out_of_range("Out of range");
        }
        
        LinkedList<T>* partList = new LinkedList<T>();
        Node* current = head;
        for (int i = 0; i < startIndex; ++i) {
            current = current->next;
        }
        for (int i = startIndex; i <= endIndex; ++i) {
            partList->Append(current->data);
            current = current->next;
        }
        return partList;
    }   

};



#endif // LINKED_LIST_H