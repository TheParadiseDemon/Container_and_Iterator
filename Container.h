
#include "Iterator.h"

#ifndef MAIN_CPP_CONTAINER_H
#define MAIN_CPP_CONTAINER_H

template <class T>
struct Node {
    T val;
    struct Node* next;
};
template<class T>
Node<T>* Find_Prev(Node<T>* head);
template<class T>
void Delete_Elem_Current(Node<T>*& head);
template<class T>
Node<T>* Merge(Node<T>* ptr1, Node<T>* ptr2);

template <class T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    void Create_List();
    void Find_Elem(T val);
    void Add_Elem(T val);
    void Delete_Next(T val);
    void Delete_List();
    void Print_List();
};

template <class T>
class Container {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;  // or also value_type*
    using reference = T&;  // or also value_type&
    using const_reference = const T&;
    using iterator = Iterator<Node<T>>;
    using const_iterator = Iterator<Node<const T>>;
    using size_type = unsigned int;

    Container() = default;

    Container(Container& a) {
        head = a.head;
        tail = a.tail;
    }

    Container(Container&& a) {
        head = std::move(a.head);
        tail = move(a.tail);
        a.head = nullptr;
        a.tail = nullptr;
    }

    Container(List<T>& a) {
        head = a.head;
        tail = a.tail;
    }

    Container(List<T>&& a) {
        head = std::move(a.head);
        tail = std::move(a.tail);
        a.tail = nullptr;
        a.head = nullptr;
    }

    ~Container() = default;

    Container& operator=(Container& a) {
        if (this != a) {
            head = a.head;
            tail = a.tail;
        }
        return this;
    }

    Container& operator=(Container&& a) {
        if (this != a) {
            head = a.head;
            tail = a.tail;
            a.head = nullptr;
            a.tail = nullptr;
        }
        return this;
    }

    constexpr Iterator<Node<T>> begin() {
        return head;
    }
};

#endif 
