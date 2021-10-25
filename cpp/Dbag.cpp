#include"Dbag.h"  
#include<algorithm>
#include<iostream>
using namespace std;

// CONSTRUCTORS and DESTRUCTOR
bag::bag(size_type initial_capacity = DEFAULT_CAPACITY){
    data = new value_type[initial_capacity];
    capacity=initial_capacity;
    used = 0;
}

bag::bag(const bag &source){
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    copy(source.data, source.data+used, data);
}

bag::~bag(){
    delete[] data;
}

 // MODIFICATION MEMBER FUNCTIONS
void bag::reserve(size_type new_capacity){
    value_type *larger_array;
    if(new_capacity==capacity)return;
    if(new_capacity<used)new_capacity = used;
    larger_array = new value_type[new_capacity];
    copy(data, data+used,larger_array);
    delete[] data;
    data = larger_array;
    capacity = new_capacity;
}

bool bag::erase_one(const value_type &target){
    size_type index=0;
    while(index<used&&data[index]!=target)index++;
    if(index==used)return false;
    data[index] = data[used-1]; //used는 빈공간의 첫 칸을 가리킴
    used--;
    return true;
}

void bag::clear(){
    delete[] data;
    used = 0;
}

void bag::insert(const value_type &entry){
    if(used==capacity)reserve(used+1);
    data[used] = entry;
    used++;
}

void bag::operator+=(const bag &addend){
    if(used+addend.used>capacity) reserve(used+addend.used);
    copy(addend.data,addend.used+addend.data,data);
    used+=addend.used;    
}

void bag::operator=(const bag &source){
    value_type *new_data;
    if(this==&source)return;
    if(capacity!=source.capacity){
        new_data = new value_type[source.capacity];
        delete[] data;
        data = new_data;
        capacity=source.capacity;
    }
}

bag operator+(const bag& b1,const bag& b2){
    bag answer(b1.size(),b2.dize());
    answer+=b1;
    answer+=b2;
    return answer;
}


