#ifndef _LINEAR_DICTIONARY_H
#define _LINEAR_DICTIONARY_H
#include "dictionary.h"
#include  <iostream> 

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

template <class K,class E>
class linear_hashTable:public  dictionary<K,E>
{
  public:
     linear_hashTable(int theDivisor)
     {
       m_divisor=theDivisor;
       m_dSize=0;

       m_table=new pair<const K,E> * [m_divisor];
       for (int i=0;i<m_divisor;i++)
       {
         m_table[i]=nullptr;
       }
     }
     ~linear_hashTable()
     {
       for (int i=0;i<m_divisor;i++)
       {
         if(m_table[i]!=nullptr)
         {
           delete m_table[i];
         }
       }
     }
     bool empty() const
     {
       return m_dSize==0;
     }
     int size() const 
     {
       return m_dSize;
     }
     pair<const K,E> * find(const K &) const ;
     int  search(const K &) const ;
     void  erase(const K &)  ;
     void  insert(const pair <const K,E> &);
  private:
     pair<const K,E> ** m_table;
     int m_dSize;
     int m_divisor;
};

template <class K,class E>
int  linear_hashTable<K,E>::search(const K& theKey) const 
{
  int start=(int) myhash(theKey);
  int nowPosition=start;

  do {
    if(m_table[nowPosition]==nullptr||m_table[nowPosition]->first==theKey)
    {
      return nowPosition;
    }
    nowPosition=(nowPosition+1) %m_divisor;
  }while(nowPosition!=start);

  return nowPosition;  //if found  ,return the Position ,else return the startKey 
}

template <class K,class E>
pair<const K,E> * linear_hashTable<K,E>::find(const K& theKey) const 
{
  int nowPosition=search(theKey);

  if(m_table[nowPosition]==nullptr||m_table[nowPosition]->first!=theKey)
    return nullptr;
  return m_table[nowPosition];
}

template <class K,class E>
void  linear_hashTable<K,E>::erase(const K & theKey)
{
  int nowPosition=search(theKey);

  if(m_table[nowPosition]==nullptr)
  {
      std::cout<<"the member is not found"<<std::endl;
      return ;
  }
  else{
     delete m_table[nowPosition];
      return ;
  }
}

template <class K,class E>
void  linear_hashTable<K,E>::insert(const pair <const K,E> & theHash)
{
  int nowPosition=search(theHash.first);

  if(m_table[nowPosition]==nullptr)
  {
    m_table[nowPosition]=new pair<const K,E>  (theHash);
    ++m_dSize;
  }
  else{
    if(m_table[nowPosition]->first==theHash.first)
    {
      m_table[nowPosition]->second=theHash.second;
    }
    else
    {
      std::cout<<"the HashTable is full"<<std::endl;
    }

  }


}


#endif
