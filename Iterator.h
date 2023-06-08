#include <iostream>
#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H

template <class T>
class Iterator {

public:

    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;  // or also value_type*
    using reference = T&;  // or also value_type&

    explicit Iterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }

    // Prefix increment
    Iterator& operator++() { m_ptr++; return *this; }

    // Postfix increment
    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    Iterator& operator=(const Iterator& a) {
        if (this != a)
            m_ptr = a.m_ptr;
        return this;
    }

    Iterator& operator=(Iterator&& a) {
        if (this != a) {
            m_ptr = std::move(a.m_ptr);
            a.m_ptr = nullptr;
        }
        return this;
    }

    ~Iterator() = default;

    void swap(Iterator& a, Iterator& b) {
        Iterator c = std::move(a);
        a = std::move(b);
        b = std::move(c);
    }

    Iterator() = default;

    Iterator(Iterator& a) {
        m_ptr = a.m_ptr;
    }

    Iterator(Iterator&& a) {
        m_ptr = std::move(a.m_ptr);
        a.m_ptr = nullptr;
    }

private:

    T* iter = nullptr;
    pointer m_ptr;

};

#endif //ITERATOR_ITERATOR_H
