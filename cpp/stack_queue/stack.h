#include<iostream>
#include<cassert>
#include<cstddef>
//템플릿 클래스에서 
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
