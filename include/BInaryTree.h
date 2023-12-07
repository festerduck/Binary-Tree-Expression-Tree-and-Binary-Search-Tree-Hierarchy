#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <class Comparable>
struct BinaryNode
{
    Comparable element;
    BinaryNode<Comparable>* left;
    BinaryNode<Comparable>* right;
};

template <class Comparable>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(BinaryNode<Comparable>* root);
    BinaryTree(const BinaryTree& t);

    virtual ~BinaryTree();

    virtual void insert(const Comparable x);

    Comparable root();
    BinaryTree left();
    BinaryTree right();

    void traverse_inOrder();
    void traverse_preOrder();
    void traverse_postOrder();

    void make_empty();

    bool empty() const;

private:
    void traverse_inOrder(BinaryNode<Comparable>* root);
    void traverse_preOrder(BinaryNode<Comparable>* root);
    void traverse_postOrder(BinaryNode<Comparable>* root);
    void deleteTree(BinaryNode<Comparable>* root);

protected:
    BinaryNode<Comparable>* create_node(Comparable data);
    BinaryNode<Comparable>* copyTree(BinaryNode<Comparable>* root);
    BinaryNode<Comparable>* tree_root;
};
