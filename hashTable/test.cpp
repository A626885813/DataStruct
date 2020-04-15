#include <utility>
#include <string>
#include <iostream>

using  namespace std;

template<>
class hash<string>
{
  public:
    size_t operator () (const string theKey)  const 
    {
      unsigned long hashValue=0;
      int length=(int ) theKey.length();
      for(int i=0;i<length;i++)
      {
        hashValue=5*hashValue+theKey.at(i);
      }
      return size_t(hashValue);
    }
};

int main()
{
  string  a("the number");
  int i=(int) hash(a);

  cout<<i<<endl;
  return 0;
}
