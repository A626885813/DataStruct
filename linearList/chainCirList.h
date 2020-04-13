#ifndef  _CHAINCIRLIST_H
#define  _CHAINCIRLIST_H

#include "linearList.h"
#include  <iostream> 
using std::ostream ;

template <typename T>
class chainNode {

  public :
    chainNode ():m_next(nullptr),m_prev(nullptr) { };
    chainNode ( const T & Element) : m_Element(Element) ,m_next(nullptr), m_prev(nullptr) 
    { }
    chainNode (const T & Element, chainNode<T> * next, chainNode<T> * perv) :m_Element(Element) ,m_next(next) ,m_prev(perv) { }
    T m_Element;
    chainNode<T> * m_next;
    chainNode<T> * m_prev;
};

template <typename T>
class  chainCirList :public linearList<T>
{
  public:
  chainCirList();
  chainCirList(const chainCirList & ) ;
  ~chainCirList();

   bool empty()  const ;

   int  size()const ;

   T & get (int theIndex) const ;

   int indexOf (const T & theElement) const;

   void erase (int theIndex) ;

   void insert (int  theIndex , const T & theElement) ;

   ostream & operator<<(ostream & out) const;

  protected:
   bool checkIndex(int theIndesx) const;
  private :
    chainNode<T> * m_pfirstNode ;
    int m_ilistSize;
};

template<typename T>
chainCirList<T>::chainCirList ()
{
  m_ilistSize =0;
  m_pfirstNode=new chainNode<T> ;
  m_pfirstNode->m_next=m_pfirstNode;
  m_pfirstNode->m_prev=m_pfirstNode;
}

template<typename T>
chainCirList<T>::chainCirList (const chainCirList<T> & theList )
{
  m_ilistSize=theList.m_ilistSize;
  if (theList.m_ilistSize==0)
  {
  m_pfirstNode=new chainNode<T> ;
  m_pfirstNode->m_next=m_pfirstNode;
  m_pfirstNode->m_prev=m_pfirstNode;
  }

  chainNode<T> * psourceNode= theList.m_pfirstNode;
  m_pfirstNode=new chainNode<T> ;
  m_pfirstNode->m_next=m_pfirstNode;
  m_pfirstNode->m_prev=m_pfirstNode;
  psourceNode=psourceNode->m_next;
  chainNode<T> * ptargetNode =m_pfirstNode;
  while(psourceNode!=theList.m_pfirstNode)
  {
    ptargetNode->m_next=new chainNode<T>(psourceNode->m_Element,ptargetNode->m_next,ptargetNode);
    ptargetNode->m_next->m_prev=ptargetNode;
    psourceNode=psourceNode->m_next;
    ++m_ilistSize;
  }

}

template<typename T>
chainCirList<T>::~chainCirList ()
{
  if (m_ilistSize==0)
  {
    return ;

  }
  chainNode<T> * psourceNode= m_pfirstNode->m_next;
  chainNode<T> * pdeleteNode=psourceNode;
  while(psourceNode->m_next!=m_pfirstNode)
  {
    psourceNode=psourceNode->m_next;
    delete pdeleteNode;
    pdeleteNode=psourceNode;
  }
  delete pdeleteNode;
  delete m_pfirstNode;
}

template<typename T>
bool chainCirList<T>::empty () const
{
  if(m_ilistSize==0)
  {
    return 0;
  }
    return 0;
}

template<typename T>
int chainCirList<T>:: size()const
{
  return m_ilistSize;
}

template<typename T>
bool chainCirList<T>::checkIndex(int theIndex) const
{
  if (theIndex <0||theIndex>m_ilistSize)
  {
    std::cout<<"location error "<<std::endl;
    return 1;
  }
    return 0;
}

template<typename T>
T & chainCirList<T>::get (int theIndex) const 
{
  if(checkIndex(theIndex))
  {
    std::cout<<"error location"<<std::endl;
  }
  else
  {
  chainNode<T> * ptargetNode =m_pfirstNode->m_next;
  for(int nowIndex=0;nowIndex<theIndex;++nowIndex)
  {
    ptargetNode=ptargetNode->m_next;
    std::cout<<"hhhhhhhhhhhhhhhhhhhh"<<std::endl;
  }
  return ptargetNode->m_Element;
  }
}
template<typename T>
int chainCirList<T>::indexOf (const T & theElement) const
{
  int targetIndex=0;
  chainNode<T> *targetNode =m_pfirstNode->m_next;
  while(targetNode !=m_pfirstNode&&targetNode->m_Element!=theElement)
  {
    ++targetIndex;
    targetNode=targetNode->m_next;
  }
    if(targetNode==m_pfirstNode)
    {
      return -1;
    }

  return  targetIndex;
}

template<typename T>
void chainCirList<T>::erase (int theIndex) 
{
  if(checkIndex(theIndex))
  {
    return ;
  }
  chainNode<T> *targetNode =m_pfirstNode->m_next;
  chainNode<T> *deleteNode ;
  for(int nowIndex=0;nowIndex<theIndex;++nowIndex)
  {
    targetNode=targetNode->m_next;
  }

  deleteNode =targetNode;
  deleteNode->m_next->m_prev=deleteNode->m_prev;
  deleteNode->m_prev->m_next=deleteNode->m_next;
  --m_ilistSize;

  std::cout<<"delete success "<<std::endl;
  delete  deleteNode;
}

template<typename T>
void chainCirList<T>::insert (int  theIndex , const T & theElement) 
{
  if(checkIndex(theIndex))
  {
    return ;
  }
  chainNode<T> * pnowNode =m_pfirstNode;
  for(int nowIndex=0;nowIndex<theIndex;++nowIndex)
  {
    pnowNode=pnowNode->m_next;
  }
    chainNode<T> * pinsertNode=pnowNode;
    pinsertNode->m_next=new chainNode<T>(theElement,pinsertNode->m_next,pinsertNode);
    pinsertNode->m_next->m_prev=pinsertNode;
    ++m_ilistSize;
}
   
template<typename T>
ostream & chainCirList<T>::operator<<(ostream & out) const
{
  chainNode<T> * pnowNode =m_pfirstNode;
  for (int nowIndex=0;nowIndex<m_ilistSize;++nowIndex)
  {
  out<<pnowNode->m_Element<<std::endl;
  pnowNode=pnowNode->m_next;
  }
  return out;
}
#endif
