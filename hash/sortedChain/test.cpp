#include "sortedChain.h"
#include <iostream>
#include <string>
using namespace std;
size_t myhash(const string theKey)
{
      unsigned long hashValue=0;
      int length=(int ) theKey.length();
      for(int i=0;i<length;i++)
      {
        hashValue=5*hashValue+theKey.at(i);
      }
      return size_t(hashValue);
};

int main ()
{
  string a("hhhhh1");
  string b("hhhhh2");
  string c("hhhhh3");
  string d("hhhhh4");
  sortedChain<int,string>   thishash;
  thishash.insert(pair<int ,string> (1,a));
  thishash.insert(pair<int ,string> (2,b));
  thishash.insert(pair<int ,string> (3,c));
  thishash.insert(pair<int ,string> (4,d));
  cout<<  thishash.find(1)->second<<endl;
  cout<<  thishash.find(2)->second<<endl;
  cout<<  thishash.find(3)->second<<endl;
  cout<<  thishash.find(4)->second<<endl;
  thishash.erase(2);
  if(thishash.find(1)!=nullptr)
  cout<<  thishash.find(1)->second<<endl;
  if(thishash.find(2)!=nullptr)
  cout<<  thishash.find(2)->second<<endl;
  if(thishash.find(3)!=nullptr)
  cout<<  thishash.find(3)->second<<endl;
  if(thishash.find(4)!=nullptr)
  cout<<  thishash.find(4)->second<<endl;




  return 0;
}
