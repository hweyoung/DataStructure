#include "linkedlist.h"
#include<cassert>

using namespace std;

std::size_t list_length(const node *head_ptr){
    size_t number=0;

    while(head_ptr!=NULL){
        head_ptr = head_ptr->link();
        number++;
    }
    return number;
}
void list_head_insert(node *previous_ptr,const node::value_type &entry){
    previous_ptr = new node(entry, previous_ptr);
}
void list_insert(node *previous_ptr, const node::value_type &entry){
    node *insert_ptr;
    insert_ptr = new node;
    insert_ptr = set_data(entry);
    insert_ptr = set_link(previous_ptr->link());
    previous_ptr = set_link(insert_ptr);
    //previous_ptr = set_link(new node(entry, previous_ptr->link()));
}
node *list_search(node *head_ptr, const node::value_type &target){
    node* curser;

    for(cursor=head_ptr;cursor!=nullptr;cursor->link()){
        if(target == cursor->data()){
            return cursor;
        }
    }
    return NULL;
}
const node *list_search(const node *head_ptr, const node::value_type &target){
    const node *cursor;
    for(cursor = head_ptr;cursor!=NULL;cursor->link())
        if(target==cursor->data())
            return cursor;
    return NULL;

}
node *list_locate(node *head_ptr, std::size_t position){
    node *cursor;
    size_t i=0;
    assert(position>0);
    for(i=1;(cursor!=NULL&&i<position);i++){
        cursor = cursor->link();
    }
    return cursor;
}
const node *list_locate(const node *head_ptr, std::size_t position){
    const node* cursor;
    size_t i;
    //assert는 prefix를 확인하기 위한 작업
    assert(position>0);
    for(i=1;(cursor!=NULL&&i<position);i++){
        cursor = cursor->link();
    }
    return cursor;
}

void list_head_remove(node *&head_ptr){
    node *remove_ptr;
    remove_ptr = set_link(head_ptr);
    head_ptr = head_ptr->link();
    delete remove_ptr;
}

void list_remove(node *previous_ptr){
    node* remove_ptr;
    remove_ptr = previous_ptr->link();
    //헤더함수에서 선언한 node class의 set_link() 생성자로 초기화 되기 때문에 참조 레퍼런스를 사용하지 않는다.
    previous_ptr = set_link(remove_ptr->link());
    delete remove_ptr;
}
void list_clear(node *&head_ptr){
    //list_head_remove사용
    while(head_ptr!=nullptr){
        list_head_remove(head_ptr);
    }
}
void list_copy(const node *source_ptr, node *&head_ptr, node *& tail_ptr){
    //list_head_insert
    //list_insert
    head_ptr = NULL; tail_ptr=NULL;
    if(source_ptr==NULL)return;
    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;
    source_ptr = source_ptr->link();

    while(source_ptr!=NULL){
        list_insert(tail_ptr,source_ptr->data());
        tail_ptr = tail_ptr->link();
        source_ptr = source_ptr->link();
    }

}