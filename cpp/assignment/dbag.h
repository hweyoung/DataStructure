#pragma once



#ifndef __BAG_DOUBLY_LINKED_LIST_H__
#define __BAG_DOUBLY_LINKED_LIST_H__
#include <cassert> 
#include <cstdlib> 
#include "dnode.h"

#include <iostream> 


using namespace std;
template<typename Item>
class bag {

public:

    typedef std::size_t size_type;
    typedef Item value_type;

    bag();

    bag(const bag& source);

    ~bag();

    void operator=(const bag& source);
    void operator+=(const bag& addend);

    bool erase_one(const value_type& target);

    size_type count(const value_type& target) const;

    value_type grab();

    void insert(const value_type& entry);

    size_type erase(const value_type& target);


    bool operator== (const bag& b);
    bool operator!= (const bag& b);


    size_type size() const { return many_nodes; }


    void show_contents();
    void sort();
    void use_list_insert_list_remove();
private:

    node<Item>* head_ptr;
    node<Item>* tail_ptr;
    size_type many_nodes;

};

template<typename Item>
bag<Item>::bag() {
    head_ptr = NULL;
    tail_ptr = NULL;
    many_nodes = 0;
}

template<typename Item>
bag<Item>::bag(const bag<Item>& source) {
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;
}

template<typename Item>
bag<Item>::~bag() {
    list_clear(head_ptr);
    many_nodes = 0;
}

template<typename Item>
void bag<Item>::operator=(const bag<Item>& source) {

    if (this == &source)
        return;

    list_clear(head_ptr);
    list_copy(source.head_ptr, head_ptr, tail_ptr); 
    many_nodes = source.many_nodes;
}

template<typename Item>
void bag<Item>::operator+=(const bag<Item>& addend) {
    node<Item>* copy_head_ptr;
    node<Item>* copy_tail_ptr;

    if (addend.many_nodes > 0) {
        list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
        copy_tail_ptr->set_fore(head_ptr);
        head_ptr->set_back(copy_tail_ptr);
        head_ptr = copy_head_ptr;
        many_nodes += addend.many_nodes;
    }
}

template<typename Item>
bool bag<Item>::erase_one(const Item& target) {
    node<Item>* target_ptr;


    target_ptr = list_search(head_ptr, target);
    if (target_ptr == NULL)
        return false;
    target_ptr->set_data(head_ptr->data());
    list_head_remove(head_ptr);
    --many_nodes;
    return true;
}

template<typename Item>
typename bag<Item>::size_type bag<Item>::count(const Item& target) const {
    size_type answer = 0;

    const node<Item>* cursor = list_search(head_ptr, target);
    while (cursor != NULL) {
        ++answer;
        cursor = cursor->link();
        cursor = list_search(cursor, target);
    }
    return answer;
}

template<typename Item>
Item bag<Item>::grab() {
    size_type i;
    const node<Item>* cursor;

    assert(size() > 0);

    i = (rand() % size()) + 1;

    cursor = list_locate(head_ptr, i);
    return cursor->data();
}

template<typename Item>
void bag<Item>::insert(const Item& entry) {
    list_head_insert(head_ptr, entry);
    ++many_nodes;
    if (tail_ptr == NULL) {
        tail_ptr = head_ptr;
    }
}

template<typename Item>
void bag<Item>::show_contents() { 
    node<Item>* cursor_ptr;
    cout << "현재 가방: ";
    for (cursor_ptr = head_ptr; cursor_ptr != NULL; cursor_ptr = cursor_ptr->link()) {
        cout << cursor_ptr->data();
        cout << " ";
    }
    cout << "\n";

}

template<typename Item>
bool bag<Item>::operator==(const bag<Item>& b) { 

    bag<Item> bag_target = b;

    for (node<Item>* cursor_ptr = head_ptr; cursor_ptr != NULL; cursor_ptr = cursor_ptr->link()) {


        if (!(bag_target.erase_one(cursor_ptr->data()))) {
            return false;
        }
    }


    if (list_length(bag_target.head_ptr) != 0) {
        return false;
    }
    else {
        return true;
    }


}

template<typename Item>
bool bag<Item>::operator!=(const bag<Item>& b) { 

    bag<Item> bag_target = b;

    for (node<Item>* cursor_ptr = head_ptr; cursor_ptr != NULL; cursor_ptr = cursor_ptr->link()) {


        if (!(bag_target.erase_one(cursor_ptr->data()))) {
            return true;
        }
    }


    if (list_length(bag_target.head_ptr) != 0) {
        return true;
    }
    else {
        return false;
    }


}


template<typename Item>
void bag<Item>::sort() {
    bag<Item> bag_temp;
    while (list_length(head_ptr) > 0) {

        Item temp = head_ptr->data();
        for (node<Item>* cursor_ptr = head_ptr->link(); cursor_ptr != NULL; cursor_ptr = cursor_ptr->link()) {


            if (cursor_ptr->data() < temp) {
                temp = cursor_ptr->data();
            }
        }
        this->erase_one(temp);
        bag_temp.insert(temp);
    }

    for (node<Item>* cursor_ptr = bag_temp.head_ptr; cursor_ptr != NULL; cursor_ptr = cursor_ptr->link()) {

        this->insert(cursor_ptr->data());
    }
    return;


}


template<typename Item>
void bag<Item>::use_list_insert_list_remove() {
    size_type i;
    node<Item>* cursor;

    assert(size() > 0);

    i = (rand() % size()) + 1;
    cout << i + 1 << "번째에 1이 삽입됐다가 삭제됩니다.\n";
    cursor = list_locate(head_ptr, i);
    this->show_contents();

    list_insert(cursor, 1);
    this->show_contents();

    list_remove(cursor->link());
    this->show_contents();

}


template<typename Item>
bag<Item> operator+(const bag<Item>& b1, const bag<Item>& b2) { 
    bag<Item> answer;

    answer.operator=(b1);
    answer.operator+=(b2);
    return answer;
}




#endif
