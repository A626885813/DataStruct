#include "maxHblt.h"
#include <iostream>

using namespace std;

int main()
{
  maxHblt<int> theHeap ;
  int elem[20];
  for (int i=0;i<20;++i)
  {
    elem[i]=i+100;
  }
  for (int i=0;i<20;++i)
  {
    theHeap.push(elem[i]);
  }
  for (int i=0;i<20;++i)
  {
  cout<<theHeap.top()<<endl;
    theHeap.pop();
  }
  return 0;
}
