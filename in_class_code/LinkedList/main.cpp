#include <cstdlib>
#include <iostream>

template <typename DT>
struct LLNode
{
  DT _data;
  LLNode * _next;
  
  LLNode(const DT & theData, LLNode * theNext = nullptr)
    :_data(theData), _next(theNext)
  {}
    
  ~LLNode();
};

template <typename DT>
std::size_t size(LLNode<DT> * head)
{
  std::size_t count = 0;
  LLNode<DT> * temp = head;
  
  while(temp != nullptr)
  {
    temp = temp->_next; 
    ++count;   
  }
  return count;
}

template <typename DT>
std::size_t recsize(LLNode<DT> * head)
{
  if (head == nullptr) return 0;
  return 1+recsize(head->_next);
}

int main (int argc, char const *argv[])
{
  LLNode<int> * head = nullptr;
  head = new LLNode<int>(7, head);
  head = new LLNode<int>(6, head);
  head = new LLNode<int>(5, head);
  head = new LLNode<int>(4, head);
  head = new LLNode<int>(3, head);
  head = new LLNode<int>(2, head);
  head = new LLNode<int>(1, head);
  
  std::cout << recsize(head);
  
  return 0;
}