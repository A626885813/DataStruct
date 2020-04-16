#ifndef _SORTEDCHAIN_H
#define _SORTEDCHAIN_H
#include "pairNode.h"
#include "dictionary.h"


template<class K,class E>
class sortedChain:public dictionary<K,E>
{
  public :
    sortedChain(): m_firstNode(nullptr),m_Size(0){ }
    ~sortedChain()
    {
      pairNode<K,E> *  nowNode=m_firstNode;
      pairNode<K,E> *  deleteNode;
      while(nowNode!=nullptr)
      {
        deleteNode=nowNode;
        nowNode=nowNode->m_next;
        delete deleteNode;
      }
      m_Size=0;
    }
     bool empty() const
     {
       return m_Size==0;
     } 
     int size() const
    {
      return m_Size;
    }
    pair<const K,E> * find(const K &) const ;
    void  erase(const K &)  ;
    void  insert(const pair <const K,E> &) ;

  private:
    pairNode<K,E> * m_firstNode;
    int m_Size;

};

template<class K,class E>
pair<const K,E> * sortedChain<K,E>::find(const K & theKey) const
{
  pairNode<K,E> *  nowNode=m_firstNode;


  while(nowNode!=nullptr &&nowNode ->m_element.first!=theKey)
  {
    nowNode=nowNode->m_next;
  }
  if(nowNode==nullptr)
  {
    return  nullptr;
  }
  return &nowNode->m_element;
}

template<class K,class E>
void  sortedChain<K,E>::erase(const K &theKey)
{
  pairNode<K,E> *  nowNode=m_firstNode;
  pairNode<K,E> *  beforeNode=nullptr;

  while(nowNode!=nullptr &&nowNode->m_element.first<theKey)
  {
    beforeNode=nowNode;
    nowNode=nowNode->m_next;
  }

  if(nowNode!=nullptr&&nowNode->m_element.first==theKey)
  {

    if(beforeNode==nullptr)
    m_firstNode=nowNode->m_next;
    else
      beforeNode->m_next=nowNode->m_next;
  delete nowNode;
  --m_Size;
  }
}

template<class K,class E>
void  sortedChain<K,E>::insert(const pair <const K,E> &thePair)
{
  pairNode< K,E> *  nowNode=m_firstNode;
  pairNode< K,E> *  beforeNode=nullptr;

  while(nowNode!=nullptr &&nowNode->m_element.first<thePair.first)
  {
    beforeNode=nowNode;
    nowNode=nowNode->m_next;
  }

  if(nowNode!=nullptr&&nowNode->m_element.first==thePair.first)
  {
    nowNode->m_element.second=thePair.second;
    return ;
  }
   pairNode< K,E> * newNode=new pairNode< K,E> (thePair,nowNode);

  if (beforeNode==nullptr) 
   m_firstNode=newNode;
  else
    beforeNode->m_next=newNode;
   ++m_Size;

}
#endif
