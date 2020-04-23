#ifndef _LINKEDBINRAYTREE_H
#define _LINKEDBINRAYTREE_H
#include "binaryTreeNode.h"
#include "binaryTree.h"
#include <iostream>
using namespace std;





template <typename  T>
class linkedBinaryTree:public  binaryTree<T>
{
  public :
    linkedBinaryTree():m_root(nullptr),m_treeSize(0){ }
    linkedBinaryTree(binaryTreeNode<T> * theroot,int theSize):m_root(theroot),m_treeSize(theSize){ }
    ~linkedBinaryTree(){erase(); }
    bool empty() const 
    {
      return m_treeSize==0;
    }
    int size() const 
    {
      return m_treeSize;
    }
    void preOrder(void (*theVisit)(T *) ) 
    {
      m_visit=theVisit;
      preOrder(m_root);
    }
    void inOrder(void (*theVisit)(T *))
    {
      m_visit=theVisit;
      inOrder(m_root);
    }
    void postOrder(void (*theVisit)(T *)) 
    {
      m_visit=theVisit;
      postOrder(m_root);
    }
    void levelOrder(void (*theVisit)(T *)) { }

    void erase()
    {
      postOrder(dispose);
      m_root=nullptr;
      m_treeSize=0;
    }
    int height() const
    {
      return height(m_root);
    }
    int height(binaryTreeNode<T> *) const;


  private :
    binaryTreeNode<T> * m_root;
    static void (*m_visit) (binaryTreeNode<T> *);
    int m_treeSize;
// following code  is some  static  will be called  by this class
    static void  preOrder(binaryTreeNode<T> * ptrtree);
    static void  inOrder(binaryTreeNode<T> *ptrtree);
    static void  postOrder(binaryTreeNode<T> * ptrtree);
    static void  dispose(binaryTreeNode<T> * ptrtree )  { delete ptrtree; }
};

template <typename  T>
static void  postOrder(binaryTreeNode<T> * ptrtree)
{
  if(ptrtree!=nullptr)
  {
    postOrder(ptrtree->m_leftNode);
    postOrder(ptrtree->m_rightNode);
    linkedBinaryTree<T>::visit(ptrtree);
  }
}

template <typename  T>
static void  inOrder(binaryTreeNode<T> * ptrtree)
{
  if(ptrtree!=nullptr)
  {
    inOrder(ptrtree->m_leftNode);
    linkedBinaryTree<T>::visit(ptrtree);
    inOrder(ptrtree->m_rightNode);
  }
}

template <typename  T>
static void  preOrder(binaryTreeNode<T> * ptrtree)
{
  if(ptrtree!=nullptr)
  {
    linkedBinaryTree<T>::visit(ptrtree);
    preOrder(ptrtree->m_leftNode);
    preOrder(ptrtree->m_rightNode);
  }
}
template <typename  T>
int linkedBinaryTree<T>::height(binaryTreeNode<T> * ptrtree) const
{
  if(ptrtree==nullptr)
  {
    return 0;
  }
  int hight_left=height(ptrtree->m_leftNode);
  int hight_right=height(ptrtree->m_rightNode);
  if(hight_left>hight_right)
    return ++hight_left;
  else
    return ++hight_right;
}

template <typename  T>
void visit (binaryTreeNode<T> * ptrtree)
{
  cout<<ptrtree->m_element<<' ';
}
#endif
