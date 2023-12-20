#include "MaxPQ.hpp"

void MaxPQ::enqueue(int key, string val)
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

void MaxPQ::swap(MaxNode *x, MaxNode *y)
{
   MaxPQ::MaxNode *tmp;
   tmp = x;
   x = y;
   y = tmp;
}

int MaxPQ::parent(int i)
{
   return i / 2;
}


int MaxPQ::leftchild(int i)
{
   return i * 2;
}


int MaxPQ::rightchild(int i)
{
   return i * 2 + 1;
}

void MaxPQ::swim(int k)
{
   if (k > 1 && (arr[parent(k)]->key) < (arr[k]->key))
   {
      swap(arr[parent(k)], arr[k]);
      swim(parent(k));
   }
}


void MaxPQ::dequeue()
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


void MaxPQ::sink(int i)
{   
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


 MaxPQ::MaxNode *MaxPQ::getHighest()
{
   return arr[1];
}


bool MaxPQ::isEmpty() const
{
   return (size == 1);
}


MaxPQ::~MaxPQ()
{
   delete[] arr;
   arr = NULL;
}


