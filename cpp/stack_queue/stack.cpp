#include "stack.h"
template<typename T>
void stack<T>::push(T element){
    if(!isFull()){
        data[used] = element;
        used++;
    }
    else std::cout<<"stack already full";
}

template<typename T>
T stack<T>::pop(){
    assesrt(!empty());
    T val = data[used-1];
    used--;
    return val;
}
template<typename T>
stack<T>::stack(){
    used =0;
}
template<typename T>
void stack<T>::clear(){
    while(!isEmpty)pop();
}
template<typename T>
void stack<T>::print_stack()const{
    assert(size()<CAPACITY));
    for(i=used-1;i>=0;i--){
        std::cout<<data[i]<<' ';
    }
    std::cout<<'\n';
}

template<typename T>
T stack<T>::top()const{
    assert(!empty());
    return data[used-1]
}