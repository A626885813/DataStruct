#ifndef  _PRIORITYQUEUE_H
#define  _PRIORITYQUEUE_H


template <typename T>
class priorityQueue
{
  public:
    virtual ~priorityQueue() { }
    virtual bool empty() const =0;
    virtual int size() const =0;
    virtual const T &top() const =0;
    virtual void pop() =0 ;
    virtual void push(const T & theElement) =0 ;
};


#endif
