#ifndef  _MAXHEAP_H
#define  _MAXHEAP_H
#include <algorithm>
#include "priorityQueue.h"

template <typename T>
class  maxHeap:public priorityQueue<T>
{
  public:
    maxHeap(int initSize=10)
    {
      if(initSize<=0)
      {
       return ;
      }
        m_heap=new T [initSize];
        m_heapSize=0;
        m_arrayLength=initSize;
    }
    ~maxHeap()
    {
      delete [] m_heap;
      m_arrayLength=m_heapSize=0;
    }
    bool empty() const
    {
      return m_heapSize==0;
    }
    int size() const 
    {
      return m_heapSize;
    }
    const T & top() const ;
    void pop()  ;
    void push(const T & theElement)  ;
    void treeTomaxHeap(T * theHeap,int theSize);

  private:
    int m_arrayLength;
    int m_heapSize;
    T * m_heap;
};

template <typename T>
const T & maxHeap<T>::top() const
{
  if (m_heapSize!=0)
  {
    return m_heap[1];
  }
}

template <typename T>
void maxHeap<T>::pop()
{
  if(m_heapSize==0)
  {
    return ;
  }

  m_heap[1].~T();
  T lastElement=m_heap[m_heapSize--];

  int nowNode=1,child=2;
  while(nowNode<=m_heapSize)
  {
    if(child<m_heapSize&&m_heap[child]<m_heap[child+1])
      ++child;
    if(lastElement>=m_heap[child])
      break;
    m_heap[nowNode]=m_heap[child];
    nowNode=child;
    child*=2;
  }
  m_heap[nowNode]=lastElement;
}

template <typename T>
void maxHeap<T>::push(const T& theElement)
{
  if(m_heapSize==m_arrayLength-1)
  {
    T * newheap=new T[m_arrayLength*2];
    copy(m_heap,m_heap+m_heapSize,newheap);
    delete [] m_heap;
    m_heap=newheap;
    m_arrayLength*=2;
    
  }
  int nowNode=++m_heapSize;
  while(nowNode!=1&&m_heap[nowNode/2]<theElement)
  {
    m_heap[nowNode]=m_heap[nowNode/2];
    nowNode/=2;
  }
  m_heap[nowNode]=theElement;

}

template <typename T>
void maxHeap<T>::treeTomaxHeap(T * theHeap,int theSize)
{
  delete []  m_heap;
  m_heap=theHeap;
  m_heapSize=theSize;


  for (int root=m_heapSize/2;root>=1;--root)
  {
    T rootElement=m_heap[root];

    int child =2*root;
    while(child<m_heapSize&&m_heap[child]<m_heap[child+1])
    {
      if(child<m_heapSize&&m_heap[child]<m_heap[child+1])
      {
        ++child;
      }
      if (rootElement>=m_heap[child])
      {
        break;
      }
      m_heap[child/2]=m_heap[child];
      child*=2;
    }
    m_heap[child/2]=rootElement;
  }
}

#endif
