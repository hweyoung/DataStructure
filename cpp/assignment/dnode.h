#pragma once



#ifndef __DNODE_H__
#define __DNODE_H__

#include <cassert>
#include <cstdlib>

template <class Item>
class node {

public:

    typedef Item value_type;

    node(const value_type& init_data = value_type(), node* init_link = NULL, node* init_link2 = NULL) {
        data_field = init_data;
        link_fore = init_link; 
        link_back = init_link2;
    }

    void set_data(const value_type& new_data) { data_field = new_data; }

    void set_fore(node* new_link) { link_fore = new_link; }
    void set_back(node* new_link)
    {
        link_back = new_link;
    }

    value_type data() const { return data_field; }

    const node* link() const { return link_fore; }

    node* link() { return link_fore; }

    const node* link2() const { return link_back; }

    node* link2() { return link_back; }

private:

    value_type data_field;
    node* link_fore;
    node* link_back;
};

template<typename Item>
size_t list_length(const node<Item>* head_ptr) {
    size_t answer = 0;
    const node<Item>* cursor;


    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        ++answer;

    return answer;
}

template<typename Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry) {

    head_ptr = new node<Item>(entry, head_ptr, NULL);
    if (head_ptr->link() != NULL) {

        head_ptr->link()->set_back(head_ptr);

    }
}

template<typename Item>
void list_insert(node<Item>* previous_ptr, const Item& entry) {
    node<Item>* insert_ptr;
    if (previous_ptr->link() != NULL)
        insert_ptr = new node<Item>(entry, previous_ptr->link(), previous_ptr);
    else
        insert_ptr = new node<Item>(entry, NULL, previous_ptr);

    previous_ptr->set_fore(insert_ptr);
    if (insert_ptr->link() != NULL) { 
        insert_ptr->link()->set_back(insert_ptr);
    }
}

template<class NodePtr, class Item>
NodePtr* list_search(NodePtr* head_ptr, const Item& target) {
    node<Item>* cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        if (target == cursor->data())
            return cursor;
    return NULL;
}
template<class NodePtr, class Item>
const NodePtr* list_search(const NodePtr* head_ptr, const Item& target) {
    const node<Item>* cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        if (target == cursor->data())
            return cursor;
    return NULL;
}

template<class NodePtr, class SizeType>
NodePtr* list_locate(NodePtr* head_ptr, size_t position) {

    size_t i;
    NodePtr* cursor;
    assert(0 < position && list_length(head_ptr) >= position); 
    for (i = 1; (cursor != NULL && i < position); ++i)
        cursor = cursor->link();



    return cursor;
}


template<class NodePtr, class SizeType>
const NodePtr* list_locate(const NodePtr* head_ptr, size_t position) {
    size_t i;
    const NodePtr* cursor;
    assert(0 < position && list_length(head_ptr) >= position);
    cursor = head_ptr;
    for (i = 1; (cursor != NULL && i < position); ++i)
        cursor = cursor->link();

    return cursor;
}

template<typename Item>
void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr) {
    head_ptr = NULL;
    tail_ptr = NULL;

    if (source_ptr == NULL)
        return;

    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;

    source_ptr = source_ptr->link();
    while (source_ptr != NULL) {
        list_insert(tail_ptr, source_ptr->data());
        tail_ptr = tail_ptr->link();
        source_ptr = source_ptr->link();
    }
}


template<typename Item>
void list_head_remove(node<Item>*& head_ptr) {
    node<Item>* remove_ptr = head_ptr;
    head_ptr = head_ptr->link();
    if (head_ptr != NULL) 
        head_ptr->set_back(NULL);

    delete remove_ptr;

}

template<typename Item>
void list_remove(node<Item>* target_ptr) {
    node<Item>* remove_ptr = target_ptr;
    remove_ptr->link2()->set_fore(remove_ptr->link());
    remove_ptr->link()->set_back(remove_ptr->link2());

    delete remove_ptr;
}

template<typename Item>
void list_clear(node<Item>*& head_ptr) {
    while (head_ptr != NULL)
        list_head_remove(head_ptr);
}






#endif
