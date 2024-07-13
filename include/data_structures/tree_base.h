#ifndef ALGORITHM_LIBRARY_TREE_BASE_H
#define ALGORITHM_LIBRARY_TREE_BASE_H

template <typename T>
class TreeBase {
public:
    virtual ~TreeBase() = default;

    virtual void insert(const T& value) = 0;
    virtual bool find(const T& value) const = 0;
    virtual void remove(const T& value) = 0;

    virtual void inorderTraversal() const = 0;
    virtual void preorderTraversal() const = 0;
    virtual void postorderTraversal() const = 0;
    virtual void levelOrderTraversal() const = 0;

    virtual int height() const = 0;
    virtual bool isBalanced() const = 0;
    virtual T findMin() const = 0;
    virtual T findMax() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
};

#endif //ALGORITHM_LIBRARY_TREE_BASE_H
