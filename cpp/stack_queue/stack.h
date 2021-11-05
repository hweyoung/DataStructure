#include<iostream>
#include<cassert>
#include<cstddef>

template<typename T>
class stack{
    typedef std::size_t size_type;
    const static size_type CAPACITY = 30;

public:
        stack();
        T pop();
        void clear();
        void push(T element);
        bool isEmpty() const {return used==0l}
        bool isFull() const {return used!=0;}
        size_type size() const {return used;}
        void print_stack()const;
        T top() const;

private:
        T data[CAPACITY];
        size_type used;

};
