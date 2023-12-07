#include "../include/BInaryTree.h"
#include <queue>

template <class Comparable>
BinaryNode<Comparable>* deepCopy(BinaryNode<Comparable>* root);


template <class Comparable>
BinaryTree<Comparable>::BinaryTree(){
  tree_root = NULL;
}

template <class Comparable>
BinaryTree<Comparable>::BinaryTree(BinaryNode<Comparable>* root){
  if(root != NULL)
    tree_root = copyTree(root);
}

template <class Comparable>
BinaryTree<Comparable>::BinaryTree(const BinaryTree& t){
  tree_root = copyTree(t.tree_root);
}

template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::copyTree(BinaryNode<Comparable>* root){
  if(root == NULL)
    return NULL;
  BinaryNode<Comparable>* node = new BinaryNode<Comparable>;
  node->element = root->element;
  node->left = copyTree(root->left);
  node->right = copyTree(root->right);
  return node;
}
template <class Comparable>
void BinaryTree<Comparable>::insert(const Comparable x){
  if(tree_root == NULL){
    tree_root = create_node(x);
    return;
  }

  queue<BinaryNode<Comparable>*> q;
  q.push(tree_root);
  while(!q.empty()){
    BinaryNode<Comparable>* temp = q.front();
    q.pop();

    if(temp->left != NULL){
      q.push(temp->left);
    }
    else{
      temp->left = create_node(x);
      return;
    }
    if(temp->right != NULL){
      q.push(temp->right);
    }
    else {
      temp->right = create_node(x);
      return;
    }
  }
}
template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::create_node(Comparable data){
  BinaryNode<Comparable>* node = new BinaryNode<Comparable>;
  if(!node){
    cout << "Memmory Allocation Failed" << endl;
    return NULL;
  }
  node->element = data;
  node->left = node->right = NULL;
  return node;
}

template <class Comparable>
Comparable BinaryTree<Comparable>::root(){
  return tree_root->element;
}

template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>::left(){
    BinaryTree<Comparable> leftTree(tree_root->left);
    return leftTree;
}

template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>::right(){
  BinaryTree<Comparable> rightTree(tree_root->right);
  return rightTree;
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_inOrder(){
  traverse_inOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_inOrder(BinaryNode<Comparable>* root){
  if(root == NULL)
    return;
  traverse_inOrder(root->left);
  cout << " " << root->element;
  traverse_inOrder(root->right);
}
template <class Comparable>
void BinaryTree<Comparable>::traverse_preOrder(){
  traverse_preOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_preOrder(BinaryNode<Comparable>* root){
  if(root == NULL)
    return;
  cout << " " << root->element;
  traverse_preOrder(root->left);
  traverse_preOrder(root->right);
}
template <class Comparable>
void BinaryTree<Comparable>::traverse_postOrder(){
  traverse_postOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_postOrder(BinaryNode<Comparable>* root){
  if(root == NULL)
    return;
  traverse_postOrder(root->left);
  traverse_postOrder(root->right);
  cout << " " << root->element;
}

template  <class Comparable>
void BinaryTree<Comparable>::make_empty(){
  deleteTree(tree_root);
}

template <class Comparable>
bool BinaryTree<Comparable>::empty() const{
  return tree_root != NULL;
}





//Destructor
template <class Comparable>
BinaryTree<Comparable>::~BinaryTree(){
   deleteTree(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::deleteTree(BinaryNode<Comparable>* root){
    if(root == NULL)
        return;
  deleteTree(root->left);
  deleteTree(root->right);
  cout << "Deleting node: " << root->element << endl;
  delete root;
}




