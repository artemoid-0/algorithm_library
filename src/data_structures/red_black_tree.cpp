#include "data_structures/red_black_tree.h"
#include <algorithm>
#include <queue>
#include <iostream>

template <typename T>
RedBlackTree<T>::RedBlackTree() : root(nullptr) {}

template <typename T>
RedBlackTree<T>::~RedBlackTree() {
    clear();
}

template <typename T>
void RedBlackTree<T>::insert(const T& value) {
    Node* node = new Node(value);
    insert(root, node);
    fixInsert(node);
}

template <typename T>
bool RedBlackTree<T>::find(const T& value) const {
    Node* node = root;
    while (node != nullptr) {
        if (value < node->data) {
            node = node->left;
        } else if (value > node->data) {
            node = node->right;
        } else {
            return true;
        }
    }
    return false;
}

template <typename T>
void RedBlackTree<T>::remove(const T& value) {
    Node* node = root;
    Node* z = nullptr;
    Node* x, * y;
    while (node != nullptr) {
        if (node->data == value) {
            z = node;
            break;
        }
        if (value < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (z == nullptr) {
        std::cout << "Value not found in the tree" << std::endl;
        return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x != nullptr) {
                x->parent = y;
            }
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK) {
        fixRemove(x);
    }

    delete z;
}

template <typename T>
void RedBlackTree<T>::inorderTraversal() const {
    inorderTraversal(root);
}

template <typename T>
void RedBlackTree<T>::preorderTraversal() const {
    preorderTraversal(root);
}

template <typename T>
void RedBlackTree<T>::postorderTraversal() const {
    postorderTraversal(root);
}

template <typename T>
void RedBlackTree<T>::levelOrderTraversal() const {
    if (root == nullptr) return;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        std::cout << node->data << " ";
        q.pop();
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
}

template <typename T>
int RedBlackTree<T>::height() const {
    return height(root);
}

template <typename T>
bool RedBlackTree<T>::isBalanced() const {
    return isBalanced(root);
}

template <typename T>
T RedBlackTree<T>::findMin() const {
    Node* node = root;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->data;
}

template <typename T>
T RedBlackTree<T>::findMax() const {
    Node* node = root;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node->data;
}

template <typename T>
bool RedBlackTree<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
void RedBlackTree<T>::clear() {
    clear(root);
    root = nullptr;
}

template <typename T>
void RedBlackTree<T>::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <typename T>
void RedBlackTree<T>::insert(Node*& root, Node*& node) {
    if (root == nullptr) {
        root = node;
        return;
    }

    if (node->data < root->data) {
        insert(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        insert(root->right, node);
        root->right->parent = root;
    }
}

template <typename T>
void RedBlackTree<T>::fixInsert(Node*& node) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;

    while ((node != root) && (node->color != BLACK) && (node->parent->color == RED)) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            Node* uncle = grandparent->left;

            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }

    root->color = BLACK;
}

template <typename T>
void RedBlackTree<T>::remove(Node*& root, Node*& node) {
    Node* y = node;
    Node* x;
    Color y_original_color = y->color;

    if (node->left == nullptr) {
        x = node->right;
        transplant(node, node->right);
    } else if (node->right == nullptr) {
        x = node->left;
        transplant(node, node->left);
    } else {
        y = minimum(node->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == node) {
            if (x != nullptr) {
                x->parent = y;
            }
        } else {
            transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }

        transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }

    if (y_original_color == BLACK) {
        fixRemove(x);
    }
}

template <typename T>
void RedBlackTree<T>::fixRemove(Node*& node) {
    while (node != root && getColor(node) == BLACK) {
        if (node == node->parent->left) {
            Node* sibling = node->parent->right;

            if (getColor(sibling) == RED) {
                setColor(sibling, BLACK);
                setColor(node->parent, RED);
                rotateLeft(node->parent);
                sibling = node->parent->right;
            }

            if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                setColor(sibling, RED);
                node = node->parent;
            } else {
                if (getColor(sibling->right) == BLACK) {
                    setColor(sibling->left, BLACK);
                    setColor(sibling, RED);
                    rotateRight(sibling);
                    sibling = node->parent->right;
                }

                setColor(sibling, getColor(node->parent));
                setColor(node->parent, BLACK);
                setColor(sibling->right, BLACK);
                rotateLeft(node->parent);
                node = root;
            }
        } else {
            Node* sibling = node->parent->left;

            if (getColor(sibling) == RED) {
                setColor(sibling, BLACK);
                setColor(node->parent, RED);
                rotateRight(node->parent);
                sibling = node->parent->left;
            }

            if (getColor(sibling->right) == BLACK && getColor(sibling->left) == BLACK) {
                setColor(sibling, RED);
                node = node->parent;
            } else {
                if (getColor(sibling->left) == BLACK) {
                    setColor(sibling->right, BLACK);
                    setColor(sibling, RED);
                    rotateLeft(sibling);
                    sibling = node->parent->left;
                }

                setColor(sibling, getColor(node->parent));
                setColor(node->parent, BLACK);
                setColor(sibling->left, BLACK);
                rotateRight(node->parent);
                node = root;
            }
        }
    }

    setColor(node, BLACK);
}

template <typename T>
void RedBlackTree<T>::rotateLeft(Node*& node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;

    if (node->right != nullptr) {
        node->right->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

template <typename T>
void RedBlackTree<T>::rotateRight(Node*& node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != nullptr) {
        node->left->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    } else if (node == node->parent->left) {
        node->parent->left = leftChild;
    } else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

template <typename T>
int RedBlackTree<T>::height(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(height(node->left), height(node->right));
}

template <typename T>
bool RedBlackTree<T>::isBalanced(Node* node) const {
    if (node == nullptr) {
        return true;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

template <typename T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::minimum(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::maximum(Node* node) const {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

template <typename T>
void RedBlackTree<T>::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

template <typename T>
void RedBlackTree<T>::setColor(Node* node, Color color) {
    if (node == nullptr) {
        return;
    }
    node->color = color;
}

template <typename T>
typename RedBlackTree<T>::Color RedBlackTree<T>::getColor(Node* node) const {
    if (node == nullptr) {
        return BLACK;
    }
    return node->color;
}

template <typename T>
void RedBlackTree<T>::inorderTraversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

template <typename T>
void RedBlackTree<T>::preorderTraversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

template <typename T>
void RedBlackTree<T>::postorderTraversal(Node* node) const {
    if (node == nullptr) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << " ";
}

template <typename T>
void RedBlackTree<T>::levelOrderTraversal(Node* node) const {
    if (node == nullptr) return;
    std::queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* current = q.front();
        std::cout << current->data << " ";
        q.pop();
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

template <typename T>
void RedBlackTree<T>::clear(Node*& node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

// Explicit template instantiation
template class RedBlackTree<int>;
template class RedBlackTree<double>;
template class RedBlackTree<std::string>;
