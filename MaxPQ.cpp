#include "MaxPQ.hpp"
template <typename MaxKey, typename MaxVal>
void MaxPQ<MaxKey, MaxVal>::enqueue(MaxKey key, MaxVal val)
{
   if (size == capacity)
   {
      cerr << "PQ is full!!!" << endl;
   }
   arr[size] = new MaxNode(key, val);
   int i = size;
   swim(i);
   size++;
}
template <typename MaxKey, typename MaxVal>
void MaxPQ<MaxKey, MaxVal>::swap(MaxNode *x, MaxNode *y)
{
   MaxPQ<MaxKey, MaxVal>::MaxNode *tmp;
   tmp = x;
   x = y;
   y = tmp;
}
template <typename MaxKey, typename MaxVal>
int MaxPQ<MaxKey, MaxVal>::parent(int i)
{
   return i / 2;
}

template <typename MaxKey, typename MaxVal>
int MaxPQ<MaxKey, MaxVal>::leftchild(int i)
{
   return i * 2;
}

template <typename MaxKey, typename MaxVal>
int MaxPQ<MaxKey, MaxVal>::rightchild(int i)
{
   return i * 2 + 1;
}
template <typename MaxKey, typename MaxVal>
void MaxPQ<MaxKey, MaxVal>::swim(int k)
{
   if (k > 1 && arr[parent(k)] < arr[k])
   {
      swap(arr[parent(k)], arr[k]);
      swim(parent(k));
   }
}

template <typename MaxKey, typename MaxVal>
void MaxPQ<MaxKey, MaxVal>::dequeue()
{
   if (size == 0)
      return;
   int i = 1;
   arr[i] = arr[size - 1];
   sink(i);
   size--;
   arr[size] = NULL;
   delete arr[size];
   return;
}

template <typename MaxKey, typename MaxVal>
void MaxPQ<MaxKey, MaxVal>::sink(int i)
{
   if(i >= size)  {return;}
   if (arr[leftchild(i)] >= arr[rightchild(i)])
   {
      swap(arr[leftchild(i)], arr[i]);
      sink(leftchild(i));
   }
   else
   {
      swap(arr[rightchild(i)], arr[i]);
      sink(rightchild(i));
   }
}

template <typename MaxKey, typename MaxVal>
typename MaxPQ<MaxKey, MaxVal>::MaxNode *MaxPQ<MaxKey, MaxVal>::getHighest()
{
   return arr[1];
}

template <typename MaxKey, typename MaxVal>
bool MaxPQ<MaxKey, MaxVal>::isEmpty() const
{
   return (size == 1);
}

template <typename MaxKey, typename MaxVal>
MaxPQ<MaxKey, MaxVal>::~MaxPQ()
{
   delete[] arr;
   arr = NULL;
}

template class MaxPQ<int, string>;
