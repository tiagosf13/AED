//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic queue (First In First Out) implementation based on an linked list
//

#ifndef _AED_lQueue_
#define _AED_lQueue_

#include <cassert>

template <typename T>
class lQueue
{
  private:
    int cur_size; // current queue size
  public:
    lQueue(void)
    {
      cur_size = 0;
    }
    ~lQueue(void)
    {
    }
    void clear(void)
    {
      cur_size = 0;
    }
    int size(void) const
    {
      return cur_size;
    }
    int is_full(void) const
    {
      return 0;
    }
    int is_empty(void) const
    {
      return (cur_size == 0) ? 1 : 0;
    }
    void enqueue(T &v)
    {
    }
    T dequeue(void)
    {
    }
    T peek(void)
    {
    }
};

#endif
