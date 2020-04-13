#ifndef _CHAINQUEUE_H
#define _CHAINQUEUE_H
#include "queue.h"
#include <iostream>

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
class chainQueue:public queue<T>
{
  public:
     chainQueue()   
     { 
       m_queueFront=new chainNode<T>;
       m_queueFront->m_pnext=nullptr;
       m_queueBack=m_queueFront;
       m_Size=0;
     }
     chainQueue(const chainQueue<T> & theQueue)   ;
     ~chainQueue()  ; 
     bool empty ()  const 
    {
       return m_Size==0;
    }

     int size()  const 
     {
       return m_Size;
     }
     T & front () const
     {
       return m_queueFront->m_pnext->m_Element;
     }
     T & back () const
     {
       return m_queueBack->m_Element;
     }

     void pop() ;
     void push (const T & theElement) ;

  private:
   chainNode<T> * m_queueFront;
   chainNode<T> * m_queueBack;
   int m_Size; 
};

template<typename T>
chainQueue<T>::chainQueue(const chainQueue<T> & theQueue)
{
  if (theQueue.m_Size==0)
  {
       m_queueFront=new chainNode<T>;
       m_queueFront->m_pnext=nullptr;
       m_queueBack=m_queueFront;
       m_Size=0;
       return ;
  }
  m_Size=theQueue.m_Size;
  chainNode<T> *sourceNode = theQueue.m_queueFront->m_pnext;
  m_queueFront=new chainNode<T>;
  chainNode<T> *nowNode = m_queueFront;
  while(sourceNode!=nullptr)
  {
    nowNode->m_pnext=new  chainNode<T>(sourceNode->m_Element,nowNode->m_pnext);
    m_queueBack=nowNode->m_pnext;
    sourceNode=sourceNode->m_pnext;
    nowNode=nowNode->m_pnext;
  }
}

template<typename T>
chainQueue<T>::~chainQueue()
{
  chainNode<T> *nowNode=m_queueFront->m_pnext;
  while(m_Size!=0)
  {
  chainNode<T> *nextNode=nowNode->m_pnext;
  delete nowNode;
  nowNode=nextNode;
  --m_Size;
  }
  delete m_queueFront;
  m_Size=0;
}


template<typename T>
void chainQueue<T>::pop() 
{
  if(m_Size!=0)
  {
    chainNode<T> *deleteNode = m_queueFront->m_pnext;
    m_queueFront->m_pnext=m_queueFront->m_pnext->m_pnext;
    delete deleteNode;
    --m_Size;
  }
  return ;
}

template<typename T>
void chainQueue<T>::push (const T & theElement) 
{
  m_queueBack->m_pnext= new chainNode<T> (theElement,m_queueBack->m_pnext);
  m_queueBack=m_queueBack->m_pnext;
  ++m_Size;
}

#endif
