#include "list_bag.h"
#include "linkedlist.h"

using namespace std;

bag::bag(){
    //initialize
    head_ptr = NULL;
    many_node = 0;
}
bag::bag(const bag &source){
    node *tail_ptr; //list_copy에서 새로 초기화해줌

    list_copy(source,head_ptr,tail_ptr);
    manynode = source.many_nodes;
}
bag::~bag(){
    list_clear(head_ptr);
    many_nodes = 0;
}
bool bag::erase_one(const value_type &target){
    node *target_ptr = list_search(head_ptr,target);
    if(target_ptr==nullptr)return false;
    target_ptr = set_data(head_ptr->data());
    list_head_remove(head_ptr);
    --many_nodes;
    return true;
}
void bag::insert(const value_type &entry){
    list_insert(head_ptr,entry);
    ++many_nodes;
}
void bag::operator+=(const bag &addend){
    node *copy_head_ptr;
    node *copy_tail_ptr;

    if(addend.many_nodes>0){
        //새로운 주소 공간으로 addend를 복사하여 생성, link를 서로 이어준다.
        list_copy(addend.head_ptr,copy_head_ptr,copy_tail_ptr);
        copy_head_ptr = set_link(head_ptr);
        head_ptr = copy_head_ptr;
        many_nodes+=addend.many_nodes;
    }
}
void bag::operator=(const bag &addend){
    node *tail_ptr;

    if(this == addend)return;

    list_clear(head_ptr);
    many_nodes=0;
    list_copy(head_ptr, addend);
    many_nodes = addend.many_nodes;
}
size_type count(const value_type &target) const{
    size_type answer = 0;
    const node* cursor;
    cursor = list_search(head_ptr, target);
    while(cursor!=NULL){
        ++answer;
        cursor = cursor->link();
        cursor = list_search(cursor,target);
    }
    return answer;
}
value_type grab() const{
    size_type i;
    const node *cursor;
    i= (rand()%size());
    cursor = list_locate(head_ptr, i);
    return cursor->data();
}