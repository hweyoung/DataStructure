#include "queue.h"

template<class Item>
queue<Item>::queue(){
    count=0;
    first=0;
    last = CAPACITY-1;
} 
template<class Item> 
Item queue<Item>::front()const{
    assert(!isempty());
    return data[first];
}
template<class Item> 
void queue<Item>::pop(){
    assert(!isempty());
    first = next_index(first);
    --count;
}
template<class Item> 
void queue<Item>::push(const Item& entry){
    assert(size()<CAPACITY);
    last = next_index(last);
    data[last]=entry;
    ++count;
}
template<class Item>
void queue<Item>::print_queue()const{
    assert(size()<CAPACITY));
    for(i=used-1;i>=0;i--){
        std::cout<<data[i]<<' ';
    }
    std::cout<<'\n';
}