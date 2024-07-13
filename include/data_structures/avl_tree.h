#ifndef ALGORITHM_LIBRARY_AVL_TREE_H
#define ALGORITHM_LIBRARY_AVL_TREE_H

#include "tree_base.h"

template <typename T>
class AVLTree : public TreeBase<T> {
public:
    AVLTree();
    ~AVLTree();

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
        int height;
        Node(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    void destroy(Node* node);
    Node* insert(Node* node, const T& value);
    Node* find(Node* node, const T& value) const;
    Node* remove(Node* node, const T& value);
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    int height(Node* node) const;
    int getBalance(Node* node) const;
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    void inorderTraversal(Node* node) const;
    void preorderTraversal(Node* node) const;
    void postorderTraversal(Node* node) const;
    void clear(Node*& node);
};

#endif //ALGORITHM_LIBRARY_AVL_TREE_H
