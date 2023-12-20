#include "MaxPQ.hpp"
template <typename MaxKey, typename MaxVal>
void MaxPQ<MaxKey, MaxVal>::enqueue(MaxKey key, MaxVal val)
{
   // if (size == capacity)
   // {
   //    cerr << "PQ is full!!!" << endl;
   // }
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
   if (k > 1 && (arr[parent(k)]->key) < (arr[k]->key))
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
   // if(i >= size)  {return;}
   // if ((arr[leftchild(i)]->key) >= (arr[rightchild(i)]->key))
   // {
   //    swap(arr[leftchild(i)], arr[i]);
   //    sink(leftchild(i));
   // }
   // else
   // {
   //    swap(arr[rightchild(i)], arr[i]);
   //    sink(rightchild(i));
   // }   
   int left = leftchild(i);
   int right = rightchild(i);
   int largest = i;

   if (left < size && arr[left]->key > arr[largest]->key)
   {
      largest = left;
   }

   if (right < size && arr[right]->key > arr[largest]->key)
   {
      largest = right;
   }

   if (largest != i)
   {
      swap(arr[i], arr[largest]);
      sink(largest);
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
