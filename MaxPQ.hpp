#ifndef MAX_HPP
#define MAX_HPP
#include <iostream>
#include <string>
using namespace std;
template <typename K, typename V>
class MaxPQ {
    private:
    class Node 
    {
        public:
        K key;
        V val;
        Node(K key, V val) : key(key), val(val){};
    };
    Node** arr;
    int capacity;
    int size;
    void swap(Node*x, Node*y);
    int leftchild(int i);
    int rightchild(int i);
    int parent(int i);
    void swim(int i);
    public:
    MaxPQ(int capacity){
        arr = new Node[capacity];
        if(arr == NULL){
            cerr<<"memory allocation failed"<<endl;
            exit(1);
        }
        this->capacity = capacity;
        size=1;
    }
    void enqueue(K key, V val);
    Node* dequeue(K key, V val);  
};
#endif