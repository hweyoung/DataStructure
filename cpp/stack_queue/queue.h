#include<iostream>
#include<cassert>
#include<cstddef>

template<class Item>
class queue{
    typedef std::size_t size_type;
    const static size_type CAPACITY = 30;

public:
    queue();    //생성자
    void pop();
    void push(const Item& entry);
    bool isempty() const{return count==0;}
    Item front() const;
    size_type size() const{return count;}
    void print_queue()const;

private:
       Item data[CAPACITY];
       size_type first;
       size_type last;
       size_type count;
       size_type next_index(size_type i) const{return (i+1)%CAPACITY;}

};
