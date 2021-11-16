#pragma once

#ifndef __STACK_H__
#define __STACK_H__
#include <cstddef>
#include <cassert>
#include <iostream>
#include "dbag.h"

template <class Item>
class stack
{
public:
    // TYPEDEFS 
    typedef std::size_t size_type;
    typedef Item value_type;
    stack() { top_ptr = NULL; }
    stack(const stack& source);
    ~stack() { list_clear(top_ptr); }
    void push(const Item& entry);
    void pop();
    
    Item top() const;
    
    size_type size() const
    {
        return list_length(top_ptr);
    }
    bool empty() const { return (top_ptr == NULL); }
   
private:
    node<Item>* top_ptr;  // Points to top of stack
    node<Item>* head_ptr;
};

template <class Item>
stack<Item>::stack(const stack<Item>& source)
{
    node<Item>* tail_ptr; 
    list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template <class Item>
void stack<Item>::push(const Item& entry)
{
    list_head_insert(top_ptr, entry);
}

template <class Item>
void stack<Item>::pop()
{
    assert(!empty());
    list_head_remove(top_ptr);
}


template <class Item>
Item stack<Item>::top() const //스택의 최상단 요소는 top_ptr이 가리키는 노드이다.
{
    assert(!empty());
    return top_ptr->data();
}


#endif