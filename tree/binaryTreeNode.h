#ifndef  _BINARYTREENODE_H
#define  _BINARYTREENODE_H



template <typename T>
struct binaryTreeNode
{
  T m_element;
  binaryTreeNode<T> *m_leftNode;
  binaryTreeNode<T> *m_rightNode;

  binaryTreeNode() :m_leftNode(nullptr),m_rightNode(nullptr) { }

  binaryTreeNode(const T& theElement):m_element(theElement),m_leftNode(nullptr),m_rightNode(nullptr) { }
  binaryTreeNode(const T& theElement,binaryTreeNode<T> *theleft,binaryTreeNode<T> * theright):m_element(theElement),m_leftNode(theleft),m_rightNode(theright) { }
};


#endif
