#include "chainCirList.h"
#include <iostream>


int main()
{
  int a=0,b=1,c=2,d=3;
  chainCirList <int>  chain;
  chain.insert(0,a);
  chain.insert(1,b);
  chain.insert(2,c);
  chain.insert(3,d);
  std::cout<<chain.get(0)<<std::endl;
  std::cout<<chain.get(1)<<std::endl;
  std::cout<<chain.get(2)<<std::endl;
  std::cout<<chain.get(3)<<std::endl;

  std::cout<< "***************************** "<<std::endl;

  chainCirList <int>  secondchain(chain);
  std::cout<<secondchain.get(0)<<std::endl;
  std::cout<<secondchain.get(1)<<std::endl;
  std::cout<<secondchain.get(2)<<std::endl;
  std::cout<<secondchain.get(3)<<std::endl;
  std::cout<<"end"<<std::endl;
}
