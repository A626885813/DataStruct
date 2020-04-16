#include "linear_hashTable.h"
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string a("hhhhh1");
  string b("hhhhh2");
  string c("hhhhh3");
  string d("hhhhh4");
  linear_hashTable< string,string>   thishash(10);
  thishash.insert(pair<string ,string> (a,a));
  thishash.insert(pair<string ,string> (b,b));
  thishash.insert(pair<string ,string> (c,c));
  thishash.insert(pair<string ,string> (d,d));
  cout<<  thishash.find(a)->second<<endl;
  cout<<  thishash.find(b)->second<<endl;
  cout<<  thishash.find(c)->second<<endl;
  cout<<  thishash.find(d)->second<<endl;
  thishash.erase(a);
  thishash.erase(d);
  if(thishash.find(a)!=nullptr)
  cout<<  thishash.find(a)->second<<endl;
  if(thishash.find(b)!=nullptr)
  cout<<  thishash.find(b)->second<<endl;
  if(thishash.find(c)!=nullptr)
  cout<<  thishash.find(c)->second<<endl;
  if(thishash.find(d)!=nullptr)
  cout<<  thishash.find(d)->second<<endl;




  return 0;
}
