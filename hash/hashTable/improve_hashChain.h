#ifndef _HASHCHAIN_H
#define _HASHCHAIN_H
#include "improve_sortedChain.h"


template <class K,class E>
class  hashChain :public  dictionary <K,E>
{
  public:
    hashChain(int thedivisor)
    {
      m_divisor=thedivisor;
      m_Size=0;
      m_table=new sortedChain<K,E> [m_divisor];
    }
    ~hashChain()
    {
      delete  []   m_table;
      m_Size=0;
    }
    bool empty() const 
    {
      return m_Size==0;
    }
    int size() const 
    {
      return m_Size;
    }
    pair<const K,E> * find(const K &theKey) const
    {
      return m_table[myhash(theKey)%m_divisor].find(theKey);
    }
    void  erase(const K & theKey) 
    {
      int homeBucket=(int)  myhash(theKey)%m_divisor;
      if(m_table[homeBucket].find(theKey))
      {
        m_table[homeBucket].erase(theKey);
        --m_Size;
      }
    }
    void  insert(const pair <const K,E> &thePair)
    {
      int homeBucket=(int)  myhash(thePair.first)%m_divisor;
      int startSize=m_table[homeBucket].size();
      m_table[homeBucket].insert(thePair);
      if(m_table[homeBucket].size()>startSize)//if no replace  ,we can plus the Size,or   not
      {
        ++m_Size;
      }
    }

  private:
    sortedChain<K,E> *m_table;
    int m_divisor;
    int m_Size;
};


#endif
