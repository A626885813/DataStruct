#ifndef _MAXHBLT_H
#define _MAXHBLT_H
#include "priorityQueue.h"
#include "binaryTreeNode.h"
#include <utility>
using namespace std;


template <typename T>
class maxHblt:public priorityQueue<T>
{
  public:
    maxHblt():m_heapSize(0),m_root(nullptr) { }
    ~maxHblt();
    bool empty() const
    {
      return m_heapSize==0;
    }
    int size() const
    {
      return m_heapSize;
    }
    const T &top() const ;
    void pop()  ;
    void push(const T & theElement) ;
    void meld(binaryTreeNode<pair<int,T> >* &x,binaryTreeNode<pair<int ,T> >* &y);
    void postOrderToErase(binaryTreeNode<pair<int,T>> *theroot);
  private:
    int m_heapSize;
    binaryTreeNode<pair<int ,T >> * m_root;
};

template <typename T>
void maxHblt<T>::postOrderToErase(binaryTreeNode<pair<int,T>> *theroot)
{
  if(theroot!=nullptr)
  {
  postOrderToErase(theroot->m_leftNode);
  postOrderToErase(theroot->m_rightNode);
  delete theroot;
  }
}
template <typename T>
maxHblt<T>::~maxHblt()
{
  postOrderToErase(m_root);
  m_root=nullptr;
  m_heapSize=0;
}
template <typename T>
void maxHblt<T>::meld(binaryTreeNode<pair<int,T> >* &x,binaryTreeNode<pair<int ,T> >* &y)
{
  if(y==nullptr)
  {
    return ;
  }
  if(x==nullptr)
  {
    x=y;
    return ;
  }
  if(x->m_element.second<y->m_element.second)
  {
    swap(x,y);
  }

  meld(x->m_rightNode,y);

  if(x->m_leftNode==nullptr)
  {
    x->m_leftNode=x->m_rightNode;
    x->m_rightNode=nullptr;
    x->m_element.first=1;
  }
  else
  {
    if(x->m_leftNode->m_element.first<x->m_rightNode->m_element.first)
    {
      swap(x->m_leftNode,x->m_rightNode);
    }
    x->m_element.first=x->m_rightNode->m_element.first+1;
  }
}

template <typename T>
const T &maxHblt<T>::top() const
{
  if(m_heapSize!=0)
  {
    return m_root->m_element.second;
  }
}

template <typename T>
void maxHblt<T>::pop()
{
  if(m_heapSize!=0)
  {
    binaryTreeNode<pair<int ,T> >*  theLeft=m_root->m_leftNode;;
    binaryTreeNode<pair<int ,T> >*  theRight=m_root->m_rightNode;
    delete m_root;
    m_root=theLeft;
    meld(m_root,theRight);
    --m_heapSize;
  }
}

template <typename T>
void maxHblt<T>::push(const T & theElement) 
{
  binaryTreeNode<pair<int ,T> >*newNode=new binaryTreeNode<pair<int,T> > (pair<int ,T >(1,theElement));
  meld(m_root,newNode);
  ++m_heapSize;
}
#endif
