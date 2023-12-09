#include "ExpressionTree.h"
#include <string>
#include <stack>

using namespace std;


ExpressionTree::ExpressionTree(){

}

ExpressionTree::ExpressionTree(ExpTreeNodePtr data) : BinaryTree<char>(data)
{

}



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
ExpressionTree ExpressionTree::left(){
  ExpressionTree left(BinaryTree<char>::tree_root->left);
  return left;
}

ExpressionTree ExpressionTree::right(){
 ExpressionTree right(BinaryTree<char>::tree_root->right);
 return right;
}

bool ExpressionTree::is_operator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;
  return false;
}

ExpressionTree::~ExpressionTree(){

}


