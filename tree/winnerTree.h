#ifndef  _WINNERTREE_H
#define  _WINNERTREE_H

template <typename  T>
class winnerTree
{
  public:
    virtual ~winnerTree()  { }
    virtual void initialize(T * thePlayer,int theNumberOfPlayers)=0;
    virtual int winner() const =0;
    virtual void rePlay(int thePlayer) =0;
};



#endif
