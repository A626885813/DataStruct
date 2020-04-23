#ifndef  _COMPLETEWINNERTREE_H
#define  _COMPLETEWINNERTREE_H
#include "winnerTree.h"
#include <iostream>
using namespace std;


template <typename T>
class  completeWinnerTree:public winnerTree<T>
{
  completeWinnerTree(T * thePlayer,int theNumberOfPlayers):m_tree(nullptr)
  {
    initalize(thePlayer,theNumberOfPlayers);
  }
  ~completeWinnerTree(){if (m_tree!=nullptr) delete []  m_tree; }
  void  initalize(T *  ,int);
  int winner()const 
  {
    return m_tree[1];
  }
  int winner(int i) const
  {
    return (i<m_numberOfPlayers)? m_tree[i]:0;
  }
  void rePlay(int);
  void output()const ;

  private :
    int m_lowExt;
    int m_offset;
    int * m_tree;
    int m_numberOfPlayers;
    T *m_player;
    void play(int ,int ,int);
};

template <typename T>
void  completeWinnerTree<T>::initalize(T *thePlayer  ,int theNumberOfPlayers)
{
  int n=theNumberOfPlayers;
  if(n<2)
    return ;

  m_player=thePlayer;
  m_numberOfPlayers=n;
  delete [] m_tree;
  m_tree=new int[n];

  //  get the  s=^log(n-1)
    int s,i;
    for (s=1;2*s<=n-1;s+=s);

    m_lowExt=2*(n-s);
    m_offset=2*s-1;

    for( i=2;i<=m_lowExt;i+=2)
    {
      play((m_offset+i)/2,i-1,i);
    }

    if(n%2==1)
    {
      play(n/2,m_tree[n-1],m_lowExt+1);
        i=m_lowExt+3;
    }
    else
    {
      i=m_lowExt+2;
    }

    for(;i<=n;i+=2)
    {
      play((i-m_lowExt+n-1)/2,i-1,i);
    }
}

template <typename T>
void completeWinnerTree<T>::rePlay(int thePlayer)
{
  int n=m_numberOfPlayers;
  if(thePlayer<=0||thePlayer>=n)
    return ;

  int matchNode,leftChild,rightChild;

  if(thePlayer<=m_lowExt)
  {
    matchNode=(m_offset+m_player)/2;
    leftChild=2*matchNode-m_offset;
    rightChild=leftChild+1;
  }
  else
  {
    matchNode=(thePlayer-m_lowExt+n-1)/2;
    if(2*matchNode==n-1)
    {
      leftChild=m_tree[2*matchNode];
      rightChild=thePlayer;
    }
    else
    {
      leftChild=2*matchNode-n+1+m_lowExt;
      rightChild=leftChild+1;
    }
  }
  m_tree[matchNode]=(m_player[leftChild]<=m_player[rightChild]) ?leftChild:rightChild;
  if(matchNode==n-1&&n%2==1)
  {
    matchNode/=2;
    m_tree[matchNode]=(m_player[m_tree[n-1]]<=m_player[m_lowExt+1]) ? m_tree[n-1]:m_lowExt+1;
  }
  matchNode/=2;
  for(;matchNode>=1;matchNode/=2)
  {
    m_tree[matchNode]=(m_player[m_tree[2*matchNode]]<=m_player[m_tree[2*matchNode+1]]) ?   m_tree[2*matchNode]:m_tree[2*matchNode+1];
  }

}

template <typename T>
void completeWinnerTree<T>::output()const 
{
  
}

template <typename T>
void completeWinnerTree<T>::play(int p,int leftChild,int rightChild)
{
  m_tree[p]=(m_player[leftChild]<=m_player[rightChild])?
leftChild:rightChild;
  while((p%2==1)&&(p>1))
  {
    m_tree[p/2]=(m_player[m_tree[p-1]]<=m_player[m_tree[p]]) ?  m_tree[p-1]:m_tree[p];
    p/=2;
  }

}

#endif
