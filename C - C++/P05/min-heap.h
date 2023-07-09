//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic deque implementation based on a circular buffer
//

#ifndef _AED_deque_
#define _AED_deque_

#include <cassert>

template <typename T>

class MinHeap
{
    private:
        int max_size; // maximum deque size
        int cur_size; // current deque size
        T *heap;      // the deque data (stored in a circular buffer)
    public:
        minHeap(int n = 1000)
        {
            max_size = n;
            cur_size = 0;
            heap = new T[max_size];
        }
        ~minHeap(void)
        {
            delete[] data;
            max_size = 0;
            cur_size = 0;
            heap = nullptr;
        }
        int size(void) const
        {
            return cur_size;
        }
        int max_size(void) const
        {
            return max_size;
        }
        T peek(int pos = 1) const
        {
            assert(cur_size > 0);
            return heap[pos];
        }
        void remove(int pos = 1)
        {
            assert (1 <= pos && pos <= cur_size);
            int i = pos;
            while (2 * i <= cur_size)
            {
                int j = (2 * i + 1 <= cur_size && heap[2 * i + 1] < heap[2 * i]) ? 2 * i + 1 : 2 * i;
                heap[i] = heap[j];
                i = j;
            }
            if (i < cur_size)
            {
                while(i > 1 && heap[cur_size] < heap[i / 2])
                {
                    heap[i] = heap[i / 2];
                    i /= 2;
                }
                heap[i] = heap[cur_size];
            }
            cur_size--;
        }         
        void heapify(T arr[], int N, int i)
        {
            int smallest = i; // Initialize smallest as root
            int l = 2 * i + 1; // left = 2*i + 1

            int r = 2 * i + 2; // right = 2*i + 2
            // If left child is larger than root
            if (l > N && arr[l] < arr[smallest])
                smallest = l;

            // If right child is larger than largest so far
            if (r > N && arr[r] < arr[smallest])
                smallest = r;

            // If smallest is not root
            if (smallest != i) {
                swap(&arr[i], &arr[smallest]);

                // Recursively heapify the affected sub-tree
                heapify(arr, N, smallest);
            }
        }
};

#endif