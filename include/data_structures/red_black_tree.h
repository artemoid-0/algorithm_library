
#ifndef ALGORITHM_LIBRARY_RED_BLACK_TREE_H
#define ALGORITHM_LIBRARY_RED_BLACK_TREE_H

#include "data_structures/tree_base.h"

template <typename T>
class RedBlackTree : public TreeBase<T> {
public:
    RedBlackTree();
    ~RedBlackTree();

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
    enum Color { RED, BLACK };

    struct Node {
        T data;
        Color color;
        Node* left;
        Node* right;
        Node* parent;
        Node(const T& value) : data(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;

    void destroy(Node* node);
    void insert(Node*& root, Node*& node);
    void fixInsert(Node*& node);
    void remove(Node*& root, Node*& node);
    void fixRemove(Node*& node);
    void rotateLeft(Node*& node);
    void rotateRight(Node*& node);

    void transplant(Node* u, Node* v);
    void setColor(Node* node, Color color);
    Color getColor(Node* node) const;
    Node* minimum(Node* node) const;
    Node* maximum(Node* node) const;

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



#endif //ALGORITHM_LIBRARY_RED_BLACK_TREE_H
