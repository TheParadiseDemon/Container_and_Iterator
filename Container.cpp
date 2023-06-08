#include "Container.h"

template<class T>
void List<T>::Create_List() {
    Node<T>* ptr = nullptr;
    head = ptr;
}

template<class T>
void List<T>::Find_Elem(T val) {
    if (head) {
        int begin = -1, ending = -1, pos = 2;
        bool found = false;
        Node<T>* current = head->next;
        if (head->val == val) {
            begin = 1;
            found = true;
        }
        while (current != head && ending == -1) {
            found = (current->val == val);
            switch (1 * (begin != -1) + 2 * found) {
            case 1: {
                ending = --pos;
                if (ending != begin)
                    std::cout << "Позиции с найденным числом: " << begin << "-" << ending << "." << std::endl;
                else
                    std::cout << "Позиция с найденным числом: " << begin << "." << std::endl;
                break;
            }
            case 2: {
                begin = pos++;
                break;
            }
            case 3: {
                pos++;
                break;
            }
            }
            current = current->next;
        }
        if (ending == -1) std::cout << "Искомый элемент отсутствует.\n";
    }
    else std::cout << "Список пуст.\n";
}

template<class T>
Node<T>* Find_Prev(Node<T>* head) {
    Node<T>* temp = head;
    Node<T>* prev = temp->next;
    while (prev->next != temp) {
        prev = prev->next;
    }
    return prev;
}

template <class T>
void List<T>::Add_Elem(T val) {
    Node<T>* temp = head;
    if (temp == nullptr) {
        Node<T>* ptr = new Node<T>();
        ptr->val = val;
        ptr->next = ptr;
        head = ptr;
    }
    else {
        Node<T>* new_node = new Node<T>();
        new_node->val = val;
        if (new_node->val >= temp->val) {
            Node<T>* prev = Find_Prev(temp);
            prev->next = new_node;
            new_node->next = temp;
            head = new_node;
        }
        else {
            temp = temp->next;
            Node<T>* prev = head;
            while ((temp != head) && (temp->val >= new_node->val)) {
                temp = temp->next;
                prev = prev->next;
            }
            prev->next = new_node;
            new_node->next = temp;
        }
    }
}

template<class T>
void Delete_Elem_Current(Node<T>*& head) {
    Node<T>* current = head;
    head = head->next;
    Node<T>* prev = Find_Prev(head);
    delete(current);
    prev->next = head;
}

template <class T>
void List<T>::Delete_Next(T val) {
    Node<T>* temp = head;
    if (temp != nullptr) {
        while (temp->next != head) {
            if (temp->val == val)
                Delete_Elem_Current(temp->next);
            temp = temp->next;
        }
    }
}

template<class T>
Node<T>* Merge(Node<T>* ptr1, Node<T>* ptr2) {
    Node<T>* a = ptr1, * b = ptr2;
    Node<T>* ans = new Node<T>();
    Node<T>* c = ans;
    bool first_head = false, second_head = false;

    switch (1 * (a != nullptr) + 2 * (b != nullptr)) {
    case 0: return nullptr;
    case 1: return a;
    case 2: return b;
    case 3: {
        if (a->val >= b->val) {
            c->next = new Node<T>;
            c->next->val = a->val;
            c->next->next = nullptr;
            a = a->next;
            c = c->next;
            first_head = true;
        }

















        else {
            c->next = new Node<T>;
            c->next->val = b->val;
            c->next->next = nullptr;
            b = b->next;
            c = c->next;
            second_head = true;
        }
    }
    }
    while ((a != ptr1 || !first_head) && (b != ptr2 || !second_head)) {
        c->next = new Node<T>;
        c = c->next;
        if ((a->val) >= (b->val)) {
            first_head = true;
            c->val = a->val;
            a = a->next;
        }
        else {
            second_head = true;
            c->val = b->val;
            b = b->next;
        }
    }

    while (a != ptr1 || !first_head) {
        first_head = true;
        c->next = new Node<T>;
        c = c->next;
        c->val = a->val;
        a = a->next;
    }

    while (b->next != ptr2 || !second_head) {
        second_head = true;
        c->next = new Node<T>;
        c = c->next;
        c->val = b->val;
        b = b->next;
    }

    c->next = ans->next;
    return ans->next;
}

template<class T>
void List<T>::Delete_List() {
    if (head != nullptr) {
        Node<T>* curr = head->next;
        while (curr != head) {
            Node<T>* delet = curr;
            curr = curr->next;
            delete (delet);
        }
    }
    head = nullptr;
}

template<class T>
void List<T>::Print_List() {
    Node<T>* temp = head;
    if (temp == nullptr)
        std::cout << "Список пуст.\n";
    else {
        do {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);
    }
}