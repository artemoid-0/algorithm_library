#include "data_structures/avl_tree.h"
#include <algorithm>
#include <stdexcept>
// Конструктор
template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

// Деструктор
template <typename T>
AVLTree<T>::~AVLTree() {
    clear();
}

// Вставка
template <typename T>
void AVLTree<T>::insert(const T& value) {
    root = insert(root, value);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::insert(Node* node, const T& value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);
    
    // LL Case
    if (balance > 1 && value < node->left->data) {
        return rotateRight(node);
    }

    // RR Case
    if (balance < -1 && value > node->right->data) {
        return rotateLeft(node);
    }

    // LR Case
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Поиск
template <typename T>
bool AVLTree<T>::find(const T& value) const {
    return find(root, value) != nullptr;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find(Node* node, const T& value) const {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return find(node->left, value);
    } else {
        return find(node->right, value);
    }
}

// Удаление
template <typename T>
void AVLTree<T>::remove(const T& value) {
    root = remove(root, value);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::remove(Node* node, const T& value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if ((node->left == nullptr) || (node->right == nullptr)) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    // LR Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RR Case
    if (balance < -1 && getBalance(node->right) <= 0) {
        return rotateLeft(node);
    }

    // RL Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Минимальный узел
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::findMin(Node* node) const {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Максимальный узел
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::findMax(Node* node) const {
    Node* current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// Высота
template <typename T>
int AVLTree<T>::height(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

template <typename T>
int AVLTree<T>::height() const {
    return height(root);
}

// Балансировка
template <typename T>
int AVLTree<T>::getBalance(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

// Обходы
template <typename T>
void AVLTree<T>::inorderTraversal() const {
    inorderTraversal(root);
}

template <typename T>
void AVLTree<T>::inorderTraversal(Node* node) const {
    if (node != nullptr) {
        inorderTraversal(node->left);
        // Process node->data
        inorderTraversal(node->right);
    }
}

template <typename T>
void AVLTree<T>::preorderTraversal() const {
    preorderTraversal(root);
}

template <typename T>
void AVLTree<T>::preorderTraversal(Node* node) const {
    if (node != nullptr) {
        // Process node->data
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

template <typename T>
void AVLTree<T>::postorderTraversal() const {
    postorderTraversal(root);
}

template <typename T>
void AVLTree<T>::postorderTraversal(Node* node) const {
    if (node != nullptr) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        // Process node->data
    }
}

// Очистка
template <typename T>
void AVLTree<T>::clear() {
    clear(root);
    root = nullptr;
}

template <typename T>
void AVLTree<T>::clear(Node*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

template <typename T>
bool AVLTree<T>::isBalanced() const {
    return getBalance(root) >= -1 && getBalance(root) <= 1;
}

template <typename T>
T AVLTree<T>::findMin() const {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    return findMin(root)->data;
}

template <typename T>
T AVLTree<T>::findMax() const {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    return findMax(root)->data;
}

template <typename T>
bool AVLTree<T>::isEmpty() const {
    return root == nullptr;
}