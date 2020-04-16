#ifndef _PAIRNODE_H
#define _PAIRNODE_H
#include <utility>


using std::pair;
template <class K,class E>
struct  pairNode
{
  public:
  pairNode():m_next(nullptr){ }
  pairNode(const pair< const K,E> &thePair, pairNode< K,E> *theNext) : m_element(thePair), m_next(theNext){ }

  pair<const K,E>  m_element;
  pairNode< K,E>  *m_next;
};



#endif
