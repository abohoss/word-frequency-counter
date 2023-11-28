#include "MaxPQ.hpp"
template<typename K, typename V>
  void MaxPQ<K,V>::enqueue(K key,V val) {
    if(size == capacity) {
        cerr<<"PQ is full!!!"<<endl;
    }
    arr[size]=new Node(key,val);
    int i = size;
    swim(i);
    size++;
  }
template<typename K, typename V>
  void MaxPQ<K,V>::swap(Node* x, Node* y) {
    MaxPQ<K,V>::Node* tmp;
    tmp=x;
    x=y;
    y=tmp;
  }
template<typename K, typename V>
int MaxPQ<K,V>::parent(int i) {
 return i / 2;
}

template<typename K, typename V>
int MaxPQ<K,V>::leftchild(int i) {
 return i * 2;
}

template<typename K, typename V>
int MaxPQ<K,V>::rightchild(int i) {
 return i*2 + 1; 
}
template<typename K, typename V>
void MaxPQ<K,V>::swim(int k) {
    if( k>1 && arr[parent(k)] < arr[k] ) {
        swap(arr[parent(k)], arr[k]);
        swim(parent(k));
    }
}


template<typename K, typename V>
 MaxPQ<K,V>::Node* dequeue() {
    if(size == 0) return NULL;
    int i = 1;
    MaxPQ<K,V>::Node* tmp = arr[i];
    arr[i] = arr[size - 1];
    sink(i);
    size--;
    arr[size] = NULL;
    delete arr[size];
    return tmp;
 }  

 template<typename K, typename V>
 void MaxPQ<K,V>::sink(int i) {
    if(arr[leftchild(i)] >= arr[rightchild(i)]) {
       swap(arr[leftchild(i)], arr[i]);
       sink( leftchild(i) );
    }
    else {
       swap(arr[rightchild(i)], arr[i]);
       sink( rightchild(i) ); 
    }
 }

 template<typename K, typename V>
 MaxPQ<K,V>::Node* getHighest() {
    return arr[1];
 }

 template<typename K, typename V>
 bool MaxPQ<K,V>::isEmpty() const {
    return ( size == 1 );
 }

 template<typename K, typename V>
 MaxPQ<K,V>::~MaxPQ() {
    delete [] arr;
    arr = NULL;
 }

template class MaxPQ<unsigned short, string>;




