#include "chainQueue.h"


using namespace std;

int main()
{
  chainQueue<int>  firstqueue;
  int a=1,b=2,c=3,d=4,e=5;
  firstqueue.push(a);
  firstqueue.push(b);
  firstqueue.push(c);
  firstqueue.push(d);
  firstqueue.push(e);
  cout<<firstqueue.front()<<endl;
  cout<<firstqueue.back()<<endl;
  cout<<"******************************"<<endl;
  cout<<"******************************"<<endl;
  cout<<"******************************"<<endl;
  chainQueue<int>  secondqueue(firstqueue);
  cout<<secondqueue.front()<<endl;
  cout<<secondqueue.back()<<endl;
  return 0;
}
