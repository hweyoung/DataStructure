#include <iostream>
#include <iomanip>


#include <cstddef>
#include <cstring>

template<typename T>
class binary_tree {

public:

    // CONSTRUCTOR
    binary_tree(binary_tree *init_left = nullptr, binary_tree *init_right = nullptr, const T &entry = T());

    // MEMBER FUNCTIONS
    const T &data() const { return data_field; }

    binary_tree *left() const { return left_field; }

    binary_tree *right() const { return right_field; }

    void set_data(const T &entry) { data_field = entry; }

    void set_left(binary_tree *new_left) { left_field = new_left; }

    void set_right(binary_tree *new_right) { right_field = new_right; }

    bool is_leaf() const { return (left_field == nullptr) && (right_field == nullptr); }


private:

    T data_field;
    binary_tree *left_field;
    binary_tree *right_field;

};


template<typename T>
binary_tree<T>::binary_tree(binary_tree *init_left, binary_tree *init_right, const T &entry) {
    left_field = init_left;
    right_field = init_right;
    data_field = entry;
}

template<typename Process, typename BinTree>
void inorder(Process f, BinTree *node_ptr) {
    if (node_ptr != nullptr) {
        inorder(f, node_ptr->left());   // template: does not actually know about data fields
        f(node_ptr->data());
        inorder(f, node_ptr->right());
    }
};

template<typename Process, typename BinTree>
void postorder(Process f, BinTree *node_ptr) {
    if (node_ptr != nullptr) {
        postorder(f, node_ptr->left());
        postorder(f, node_ptr->right());
        f(node_ptr->data());
    }
};

template<typename Process, typename BinTree>
void preorder(Process f, BinTree *node_ptr) {
    if (node_ptr != nullptr) {
        f(node_ptr->data());
        preorder(f, node_ptr->left());
        preorder(f, node_ptr->right());
    }
};

template<typename T, typename SizeType>
void print(binary_tree<T> *node_ptr, SizeType depth) {
    if (node_ptr != nullptr) {
        print(node_ptr->right(), depth + 1);
        std::cout << std::setw(4 * depth) << "";    // indent 4 * depth spaces.
        std::cout << node_ptr->data() << std::endl;
        print(node_ptr->left(), depth + 1);
    }
};

template<typename T>
void tree_clear(binary_tree<T> *&root_ptr) {
    binary_tree<T> *child;
    if (root_ptr != nullptr) {
        child = root_ptr->left();
        tree_clear(child);
        child = root_ptr->right();
        tree_clear(child);
        delete root_ptr;
        root_ptr = nullptr;
    }
}

template<typename T>
std::size_t tree_size(const binary_tree<T> *node_ptr) {
    if (node_ptr == nullptr)
        return 0;
    else
        return 1 + (tree_size(node_ptr->left()) + tree_size(node_ptr->right()));
}

template<typename T>
binary_tree<T> *tree_copy(const binary_tree<T> *root_ptr) {
    binary_tree<T> *lptr;
    binary_tree<T> *rptr;
    if (root_ptr == nullptr) return nullptr;
    else {
        lptr = tree_copy(root_ptr->left());
        rptr = tree_copy(root_ptr->right());
        return new binary_tree<T>(root_ptr->data(), lptr, rptr);
    }
}

// //remove 함수 
// template<typename T>
// binary_tree<T> bst_remove(binary_tree<T> *&root_ptr,const T& target){
//     binary_tree *oldroot_ptr = root_ptr;
//     root_ptr = root_ptr->right();
//     delete oldroot_ptr;

//     //왼쪽 노드가 있을 경우 왼쪽 subtree의 가장 큰 값을 찾아 제거 후 data 삽입
//     bst_remove_max(root_ptr->left(),root_ptr->data());
// }

// //max값 search후 remove함수 
// //삭제하려는 노드의 왼쪽 subtree에서 가장 큰 값을 삭제 후 target node에 데이터 삽입
// template<typename T>
// binary_tree<T> bst_remove_max(binary_tree<T> *&root_ptr,const T& removed_Item){
//     binary_tree *oldroot_ptr = root_ptr;
//     removed_Item = root_ptr->data();
//     oldroot_ptr = root_ptr;
//     root_ptr = root_ptr->left(); 
//     delete oldroot_ptr;
// } 

