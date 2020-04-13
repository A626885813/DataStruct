#ifndef  _ARRAYSTACK_H
#define  _ARRAYSTACK_H
#include "stack.h"
#include <algorithm>
#include <iostream>
using  namespace std;

template <typename T>
class arrayStack:public stack <T>
{

  public:
    arrayStack(int initCapacity =3)
    {
      if (initCapacity<0)
      {
        cout<<"initCapacity error"<<endl;
        return ;
      }
      stack =new  T  [initCapacity];
      arrayLength=initCapacity;
      stackTop=-1;
    }
     ~arrayStack()  
     {
       delete [] stack;
     }
     bool empty () const 
     {
       return stackTop==-1;
     }
     int size()  const 
     {
       return stackTop+1;
     }
     T & top () ;
     void pop() ;
     void push (const T & theElement);
  private:
     T* stack;
     int stackTop;
     int arrayLength;
};

template<typename T>
T & arrayStack<T>::top () 
{
  if(stackTop==-1)
  {
    cout<<"number error"<<endl;
  }
  return stack [stackTop];
}

template<typename T>
void arrayStack<T>::pop() 
{
  if(stackTop==-1)
  {
    cout<<"number error"<<endl;
    return ;
  }
   return stack[stackTop--].~T();
}

template<typename T>
void arrayStack<T>::push (const T & theElement)
{
  if (stackTop==arrayLength-1)
  {
    cout<<"number is full ,will expand the memory"<<endl;
    T *  newstack =new T[arrayLength*2];
    copy(stack,stack+arrayLength,newstack);
    delete [] stack;
    stack =newstack;
  }
  stack[++stackTop]=theElement;
}


#endif
