#include "chainStack.h"
#include <iostream>


using namespace std;
int main()
{
  chainStack<int>  theStack;
  int a=1,b=2,c=3,d=4,e=5;
  theStack.push(a);
  theStack.push(b);
  theStack.push(c);
  theStack.push(d);
  theStack.push(e);
  cout<<theStack.top()<<endl;
  theStack.pop();
  cout<<theStack.top()<<endl;
  theStack.pop();
  cout<<theStack.top()<<endl;
  theStack.pop();
  cout<<theStack.top()<<endl;
  theStack.pop();
  cout<<theStack.top()<<endl;
  theStack.pop();
  cout<<"\n"<<endl;
 
  cout<<"*******************"<<endl;

 chainStack<int>  secondStack(theStack);
  secondStack.push(a);
 cout<<secondStack.top()<<endl;
  secondStack.push(b);
 cout<<secondStack.top()<<endl;
  secondStack.push(c);
 cout<<secondStack.top()<<endl;
  secondStack.push(d);
 cout<<secondStack.top()<<endl;
 
  return 0;

}
