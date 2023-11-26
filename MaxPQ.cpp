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
    if( arr[parent(k)] < arr[k] ) {
        swap(arr[parent(k)], arr[k]);
        swim(parent(k));
    }
}






