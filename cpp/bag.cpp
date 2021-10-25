#include"bag.h"
#include<assert.h>
#include<algorithm>


bag::bag(){
    used = 0;
    
}
bool bag::erase_one(const value_type &target){
    size_t index;
    while((index<used)&&(data[index]!=target)){
        ++index;
        if(index==used) return false;

        --used;
        data[index] = data[used];
        return true;
    }

}
void bag::insert(const value_type &entry){
    assert(size()<CAPACITY);
    data[used++] = entry;
}
void bag::operator+=(const bag &addend){
    size_t index;
    copy(addend.data,addend.data+addend.used,data+used);
    used +=addend.used;
}
size_t bag::size() const{
    return used;                                                                                    
}