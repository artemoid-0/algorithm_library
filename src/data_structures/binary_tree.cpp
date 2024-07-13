#include <stdexcept>
#include "data_structures/binary_tree.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    clear();
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    insert(root, value);
}

template <typename T>
bool BinarySearchTree<T>::find(const T& value) const {
    return find(root, value);
}

template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
    remove(root, value);
}

template <typename T>
void BinarySearchTree<T>::inorderTraversal() const {
    inorderTraversal(root);
}

template <typename T>
void BinarySearchTree<T>::preorderTraversal() const {
    preorderTraversal(root);
}

template <typename T>
void BinarySearchTree<T>::postorderTraversal() const {
    postorderTraversal(root);
}

template <typename T>
void BinarySearchTree<T>::levelOrderTraversal() const {
    // Implement level order traversal if needed
}

template <typename T>
int BinarySearchTree<T>::height() const {
    return height(root);
}

template <typename T>
bool BinarySearchTree<T>::isBalanced() const {
    return isBalanced(root);
}

template <typename T>
T BinarySearchTree<T>::findMin() const {
    return findMin(root);
}

template <typename T>
T BinarySearchTree<T>::findMax() const {
    return findMax(root);
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
void BinarySearchTree<T>::clear() {
    clear(root);
}

template <typename T>
void BinarySearchTree<T>::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <typename T>
void BinarySearchTree<T>::insert(Node*& node, const T& value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
    // If value is equal to node->data, do nothing (assuming no duplicates)
}

template <typename T>
bool BinarySearchTree<T>::find(Node* node, const T& value) const {
    if (node == nullptr) {
        return false;
    } else if (value < node->data) {
        return find(node->left, value);
    } else if (value > node->data) {
        return find(node->right, value);
    } else {
        return true; // found
    }
}

template <typename T>
void BinarySearchTree<T>::remove(Node*& node, const T& value) {
    if (node == nullptr) {
        return;
    }

    if (value < node->data) {
        remove(node->left, value);
    } else if (value > node->data) {
        remove(node->right, value);
    } else {
        // Case 1: No child or one child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            node = temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            node = temp;
        } else {
            // Case 2: Two children
            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            node->data = successor->data;
            remove(node->right, successor->data);
        }
    }
}

template <typename T>
int BinarySearchTree<T>::height(Node* node) const {
    if (node == nullptr) {
        return -1; // height of empty tree is -1
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + std::max(leftHeight, rightHeight);
}

template <typename T>
bool BinarySearchTree<T>::isBalanced(Node* node) const {
    if (node == nullptr) {
        return true; // empty tree is balanced
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::abs(leftHeight - rightHeight) <= 1 &&
           isBalanced(node->left) &&
           isBalanced(node->right);
}

template <typename T>
T BinarySearchTree<T>::findMin(Node* node) const {
    if (node == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->data;
}

template <typename T>
T BinarySearchTree<T>::findMax(Node* node) const {
    if (node == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    while (node->right != nullptr) {
        node = node->right;
    }
    return node->data;
}

template <typename T>
void BinarySearchTree<T>::inorderTraversal(Node* node) const {
    if (node) {
        inorderTraversal(node->left);
        // Process node->data
        inorderTraversal(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::preorderTraversal(Node* node) const {
    if (node) {
        // Process node->data
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::postorderTraversal(Node* node) const {
    if (node) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        // Process node->data
    }
}

template <typename T>
void BinarySearchTree<T>::clear(Node*& node) {
    destroy(node);
    node = nullptr;
}

// Explicit instantiation of templates to avoid linker errors
template class BinarySearchTree<int>;
template class BinarySearchTree<double>;
// Add more instantiations as needed for other types