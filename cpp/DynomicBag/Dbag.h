#include<cstdlib>
class bag{
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30;

    // CONSTRUCTORS and DESTRUCTOR
    bag(size_type initial_capacity = DEFAULT_CAPACITY);

    bag(const bag &source);

    ~bag();

    // MODIFICATION MEMBER FUNCTIONS
    void reserve(size_type new_capacity);

    bool erase_one(const value_type &target);

    size_type erase(const value_type &target);

    void clear();

    void insert(const value_type &entry);

    void operator+=(const bag &addend);

    size_type operator-=(const bag &addend);

    void operator=(const bag &source);

    value_type operator[](int x);


    // CONSTANT MEMBER FUNCTIONS
    size_type size() const { return used; }

    bool contains(const value_type &target) const;

    size_type count(const value_type &target) const;

    size_type get_capacity() const { return capacity; }

    void print_bag() const;

private:
    value_type *data;
    size_type used;
    size_type capacity;
};

// NONMEMBER FUNCTIONS for the bag class
bag operator+(const bag &b1, const bag &b2);

bag operator-(const bag &b1, const bag &b2);
