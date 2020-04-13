#ifndef  __CHAINLISTCPP_H
#define  __CHAINLISTCPP_H
#include <iostream>
#include "linearList.h"
using namespace std;

template  <class T>
struct chainNode 
{
  T element;
  chainNode<T> *next;

  chainNode(){ }
  chainNode (const T & element)
  {
    this->element=element;
  }
  chainNode (const T & element,chainNode<T> * next)
  {
    this->element=element;
    this->next=next;
  }
};

template<class T>
class chain:public linearList<T>//template  must  define  in the .h fine
{
  public :
    chain(int initcapacity=10);
    chain(const chain<T> &);
    ~chain();


    bool empty()  const  {return listSize==0;}
    int size()  const {
      return listSize;
    }
    T& get(int theIndex)  const;
    int indexOf(const T& theElement)  const;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(ostream & out)  const;


  protected:
    void  checkIndex(int theIndex)  const;
    chainNode<T> *  firstNode;
    int listSize;
};

template<class T>
void chain<T>::checkIndex(int theIndex)  const
{
  if(theIndex<0||theIndex>=listSize)
  {
    //ostringstream s;
    cout<<"index = "<<theIndex<<" size = "<<listSize;
    //throw illegalIndex(s.str());
  }
}

template <class T>
chain<T>::chain(int initcapacity)
{
  if(initcapacity <1)
  {
  //  ostringstream  s;
    cout<<"Iintial capacity"<<initcapacity<<"Must be  >0";
   // throw  illegalParameterValue(s.str());
  }
firstNode =NULL;
listSize=0;
}

template<class T>
chain<T>::chain(const chain<T> & theList)
{
  listSize=theList.listSize;

  if(listSize==0)
  {
    firstNode =NULL;
    return ;
  }
chainNode<T> * sourceNode =theList.firstNode;//save the list which we want to copy
firstNode=new chainNode<T> (sourceNode->element);//save the first Node  for the list which we want to create
sourceNode =sourceNode->next;
chainNode<T> * targetNode=firstNode;//this is  the node that we deal with now
while(sourceNode!=NULL)
{
  targetNode->next=new chainNode <T> (sourceNode->element);
  targetNode=targetNode->next;
  sourceNode=sourceNode->next;
}
targetNode->next=NULL;

}

template<class T>
chain<T>::~chain()
{
  while(firstNode !=NULL)//if listSize==0  ,it will  release  automatic
  {
    chainNode<T> * nextNode=firstNode->next;
    delete firstNode;//release the memory to avoid  memory leak 
    firstNode =nextNode;
  }
}

template<class T>
T& chain<T>::get(int theIndex)  const
{
  checkIndex(theIndex);

  chainNode<T> * currentNode=firstNode;
  for(int i=0;i<theIndex;i++)
    currentNode =currentNode->next;//move to  the elem  we want
  return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{

  chainNode<T> * currentNode=firstNode;
  int index=0;
  while(currentNode!=NULL&&currentNode->element != theElement)
  {
    currentNode=currentNode->next;
    index++;
  }
  if(currentNode==NULL)
    return -1;
  else
    return index;
}

template<class T>
void  chain<T>::erase(int theIndex)
{
  checkIndex(theIndex);

  chainNode<T> *  deleteNode;
  if(theIndex ==0)
  {
    deleteNode=firstNode;//delete the firstNode  
    firstNode=firstNode->next;//at first  we should   save the next  ptrNode  ,after that we can  delete it
  }
  else
  {
    chainNode<T>* p=firstNode;
    for(int i=0;i<theIndex-1;i++)
      p=p->next;

    deleteNode=p->next;
    p->next=p->next->next;
  }
  listSize--;
  delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex,const T& theElement)
{
  if(theIndex<0||theIndex>listSize)
  {
    //ostringstream s;
    cout<<"index ="<<theIndex<<"size = "<<listSize;
    //throw illegalIndex(s.str());
    return ;
  }
  if(theIndex ==0)
  {
    firstNode =new chainNode<T> (theElement,firstNode);//create the first member  
  }
  else
  {
    chainNode<T> * p=firstNode;
    for(int i=0;i<theIndex-1;i++)
      p=p->next;
    p->next=new chainNode<T> (theElement,p->next);//find the position  and  make it
  }
  listSize++;
}

template<class T>
void chain<T>::output(ostream & out) const
{
  for (chainNode<T> * currentNode =firstNode;currentNode !=NULL;currentNode->next)
    out<<currentNode->element<<" ";
}
template<class T>
ostream& operator <<(ostream & out ,const chain<T> & x)
{
  x.output(out);
  return out;
}
#endif
