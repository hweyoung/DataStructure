#include<cstdlib>
#include "linkedlist.h"

class bag{
    public:
        typedef std::size_t size_type;
        typedef node::value_type value_type;

        bag();
        bag(const bag &source);
        ~bag();
        size_type erase(const value_type &target);
        bool erase_one(const value_type &target);
        void insert(const value_type &entry);
        void operator+=(const bag &addend);
        void operator=(const bag &addend);
        size_type size() const{return many_nodes;}//inline함수임
        size_type count(const value_type &target) const;
        value_type grab() const;
   
    private:
        node *head_ptr;
        size_type many_nodes;

};

bag operator+(const bag &b1, const bag &b2);
