#ifndef _ARRAYQUEUE_H
#define _ARRAYQUEUE_H
#include "queue.h"
#include <iostream>
#include <algorithm>


using namespace std;
template <typename T>
class arrayQueue:public queue <T>
{

  public:
    arrayQueue(int initCapacity =3)
    {
      if (initCapacity<0)
      {
        cout<<"initCapacity error"<<endl;
        return ;
      }
      queue =new  T  [initCapacity];
      arrayLength=initCapacity;
      m_queueFront=m_queueBack=0;
      m_Size=0;
    }
    arrayQueue(const arrayQueue<T> &  theArrayQueue);
     ~arrayQueue()  
     {
       delete [] queue;
     }
     bool empty () const 
     {
       return m_queueFront==m_queueBack;
     }
     int size()  const 
     {
       return m_Size;
     }
     T& front() const
     {
       return  queue[(m_queueFront+1)%arrayLength];
     }

     T& back() const
     {
       return  queue[(m_queueBack)%arrayLength];
     }
     void pop() ;
     void push (const T & theElement);
  private:
     T* queue;
     int m_Size;
     int m_queueFront;
     int m_queueBack;
     int arrayLength;
};

template<typename T>
arrayQueue<T>::arrayQueue(const arrayQueue<T> &  theArrayQueue)
{
  queue=new T[theArrayQueue.arrayLength];
  copy(theArrayQueue.queue,theArrayQueue.queue+theArrayQueue.arrayLength,queue);
  m_Size=theArrayQueue.m_Size;
  m_queueBack=theArrayQueue.m_queueBack;
  m_queueFront=theArrayQueue.m_queueFront;
  arrayLength=theArrayQueue.arrayLength;
}
template<typename T>
void arrayQueue<T>::pop() 
{
  if(m_queueFront==m_queueBack)
  {
    cout<<"number too few"<<endl;
    return ;
  }
  m_queueFront=(m_queueFront+1)%arrayLength;
   return queue[m_queueFront].~T();
  --m_Size;
}

template<typename T>
void arrayQueue<T>::push (const T & theElement)
{
  if ((m_queueBack+1)%arrayLength==m_queueFront)
  {
    cout<<"number is full ,will expand the memory"<<endl;
    T *  newqueue =new T[arrayLength*2];
    int start =(m_queueFront+1)%arrayLength;
    if(start<2)
    {
    copy(queue+start,queue+arrayLength+start-1,newqueue);
    }
    else
    {
    copy(queue+start,queue+arrayLength,newqueue);
    copy(queue,queue+m_queueBack+1,newqueue+arrayLength+start);
    }
    m_queueFront=2*arrayLength-1;
    m_queueBack=arrayLength-2;
    arrayLength*=2;
    delete [] queue;
    queue =newqueue;
  }
  m_queueBack=(m_queueBack+1)%arrayLength;
  queue[m_queueBack]=theElement;
  ++m_Size;
}



#endif
