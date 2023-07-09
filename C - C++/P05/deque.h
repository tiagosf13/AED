//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic deque implementation based on a circular buffer
//

#ifndef _AED_deque_
#define _AED_deque_

#include <cassert>

template <typename T>
class deque
{
  private:
    int max_size; // maximum deque size
    int cur_size; // current deque size
    int head;     // index of the first element
    int tail;     // index of the last element
    T *data;      // the deque data (stored in a circular buffer)
  private:
    int increment_index (int i) { return (i < max_size - 1) ? i + 1 : 0; }
    int decrement_index (int i) { return (i > 0) ? i - 1 : max_size - 1; }
  public:
    deque(int n = 100)
    {
      max_size = n;
      cur_size = 0;
      head = 1;
      tail = 0;
      data = new T[max_size];
    }
    ~deque(void)
    {
      delete[] data;
      max_size = 0;
      cur_size = 0;
      head = 1;
      tail = 0;
      data = nullptr;
    }
    void clear(void)
    {
      cur_size = 0;
      head = 1;
      tail = 0;
    }
    int size(void) const
    {
      return cur_size;
    }
    int is_full(void) const
    {
      return (cur_size == max_size) ? 1 : 0;
    }
    int is_empty(void) const
    {
      return (cur_size == 0) ? 1 : 0;
    }
    void insert_at_head(T v)
    {
      assert(cur_size < max_size);
      head = decrement_index(head);
      data[head] = v;
      cur_size++;
    }
    T remove_head(void)
    {
      assert(cur_size > 0);
      T v = data[head];
      head = increment_index(head);
      cur_size--;
      return v;
    }
    T peek_head(void)
    {
      assert(cur_size > 0);
      return data[head];
    }
    void insert_at_tail(T v)
    {
      assert (cur_size < max_size);
      tail  = increment_index(tail);
      data[tail] = v;
      cur_size++;
    }
    T remove_tail(void)
    {
      assert(cur_size > 0);
      T v = data[tail];
      tail  = decrement_index(tail);
      cur_size--;
      return v;
    }
    T peek_tail(void)
    {
      assert(cur_size > 0);
      return data[tail];
    }
};

#endif
