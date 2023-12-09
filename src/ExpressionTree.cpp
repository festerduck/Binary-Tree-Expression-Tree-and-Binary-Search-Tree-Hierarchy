#include "ExpressionTree.h"
#include <string>
#include <stack>

using namespace std;


//All the Constructors and Destructor of the parent class will perform
ExpressionTree::ExpressionTree(){

}

ExpressionTree::ExpressionTree(ExpTreeNodePtr data) : BinaryTree<char>(data)
{

}


//Method to Create an Expression tree
//This method will parse the string given as a parameter
//then evaluate and perform the two functions
//1- If they are operands, it will push these two the stack
//2- If they are operator, it will pop the two top element from the expStack
//then make these the child of the new node with operator as their parent
//After making these children, the node will be pushed to the stack
void ExpressionTree::create_expression_tree(std::string expression){
  stack<ExpTreeNodePtr> expStack;
  for (int i = 0; i < expression.length(); i++) {
   if(is_operator(expression[i]))
   {
    ExpTreeNodePtr operand1 = expStack.top();
    expStack.pop();
    ExpTreeNodePtr operand2 = expStack.top();
    expStack.pop();
    ExpTreeNodePtr newNode = BinaryTree<char>::create_node(expression[i]);
    newNode->left = operand2;
    newNode->right = operand1;
    expStack.push(newNode);
   }
   else {
    ExpTreeNodePtr newNode = BinaryTree<char>::create_node(expression[i]);
    expStack.push(newNode);
   }
  }
  BinaryTree<char>::tree_root = expStack.top();



}
//This method will return the left tree of the original tree
ExpressionTree ExpressionTree::left(){
  ExpressionTree left(BinaryTree<char>::tree_root->left);
  return left;
}
//Similar to the left(), this method will return the right of the tree
ExpressionTree ExpressionTree::right(){
 ExpressionTree right(BinaryTree<char>::tree_root->right);
 return right;
}

//This method evaluates whether a given character is an operator or not
//this method is used in create_expression_tree() instead of creating a long if else chain
bool ExpressionTree::is_operator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;
  return false;
}

ExpressionTree::~ExpressionTree(){

}


