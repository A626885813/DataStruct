#ifndef _CHAINSTCAK_H
#define _CHAINSTCAK_H
#include "stack.h"

template<typename T>
struct chainNode 
{
  public:
    chainNode() { }
    chainNode(const T & theElement ):m_Element(theElement),m_pnext(nullptr) { }
    chainNode(const T & theElement ,chainNode<T> * theNext):m_Element(theElement),m_pnext(theNext) { }
    T m_Element ;
    chainNode<T> * m_pnext;
};

template<typename T>
class chainStack:public stack<T>
{
  public:
     chainStack()   
     { 
       m_Stack=new chainNode<T>; 
       m_Stack->m_pnext=nullptr;
       m_topStack=m_Stack;
       m_Size=0;
     }
     chainStack(const chainStack<T> & theStack)   ;
     ~chainStack()  ; 
     bool empty ()  const 
    {
       return m_Size==0;
    }

     int size()  const 
     {
       return m_Size;
     }

     T & top () 
     {
       if(!empty())
       return m_topStack->m_Element;
     }
     
     void pop() ;
     void push (const T & theElement) ;

  private:
   chainNode<T> * m_Stack;
   chainNode<T> * m_topStack;
   int m_Size; 
};

template<typename T>
chainStack<T>::chainStack(const chainStack<T> & theStack)
{
  if (theStack.m_Size==0)
  {
       m_Stack=new chainNode<T>; 
       m_Stack->m_pnext=nullptr;
       m_topStack=m_Stack;
       m_Size=0;
       return ;
  }
  m_Size=theStack.m_Size;
  chainNode<T> *sourceNode = theStack.m_topStack;
  m_Stack=new chainNode<T>;
  chainNode<T> *nowNode = m_Stack;
  while(sourceNode!=nullptr)
  {
    nowNode->m_pnext=new  chainNode<T>(sourceNode->m_Element,nowNode->m_pnext);
    sourceNode=sourceNode->m_pnext;
    nowNode=nowNode->m_pnext;
  }
  m_topStack=m_Stack->m_pnext;
}

template<typename T>
chainStack<T>::~chainStack()
{
  chainNode<T> *nowNode=m_Stack->m_pnext;
  while(m_Size!=0)
  {
  chainNode<T> *nextNode=nowNode->m_pnext;
  delete nowNode;
  nowNode=nextNode;
  --m_Size;
  }
  delete m_Stack;
  m_Size=0;
}


template<typename T>
void chainStack<T>::pop() 
{
  if(m_Size!=0)
  {
  m_Stack->m_pnext=m_topStack->m_pnext;
  delete m_topStack;
  m_topStack=m_Stack->m_pnext;
  --m_Size;
  }
  return ;
}

template<typename T>
void chainStack<T>::push (const T & theElement) 
{
  m_Stack->m_pnext= new chainNode<T> (theElement,m_Stack->m_pnext);
  m_topStack=m_Stack->m_pnext;
  ++m_Size;
}

#endif
