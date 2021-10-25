#include<cstdlib>
class bag{
    public:
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 200;

        bag();
        size_type erase(const value_type &target);
        bool erase_one(const value_type &target);
        void insert(const value_type &entry);
        void operator+=(const bag &addend);
        size_type size() const;
        size_type count(const value_type &target) const;

    private:
        value_type data[CAPACITY];
        size_type used;
};