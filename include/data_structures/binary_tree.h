#ifndef ALGORITHM_LIBRARY_BINARY_TREE_H
#define ALGORITHM_LIBRARY_BINARY_TREE_H

#include "data_structures/tree_base.h"

template <typename T>
class BinarySearchTree : public TreeBase<T> {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const T& value) override;
    bool find(const T& value) const override;
    void remove(const T& value) override;

    void inorderTraversal() const override;
    void preorderTraversal() const override;
    void postorderTraversal() const override;
    void levelOrderTraversal() const override;

    int height() const override;
    bool isBalanced() const override;
    T findMin() const override;
    T findMax() const override;
    bool isEmpty() const override;
    void clear() override;

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        explicit Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void destroy(Node* node);
    void insert(Node*& node, const T& value);
    bool find(Node* node, const T& value) const;
    void remove(Node*& node, const T& value);
    int height(Node* node) const;
    bool isBalanced(Node* node) const;
    T findMin(Node* node) const;
    T findMax(Node* node) const;
    void inorderTraversal(Node* node) const;
    void preorderTraversal(Node* node) const;
    void postorderTraversal(Node* node) const;
    void levelOrderTraversal(Node* node) const;
    void clear(Node*& node);
};


#endif //ALGORITHM_LIBRARY_BINARY_TREE_H
