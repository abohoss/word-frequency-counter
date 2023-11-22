#ifndef LLRB
#define LLRB
#include <iostream>
using namespace std;

enum Color { RED, BLACK };
template <typename V,typename K>
class LLRB {
private:
    class Node {
        public:
        Node* left,right;
        V val;
        K key;
        Color color;
        Node(K key, V val): left(NULL),right(NULL),val(val),key(key), color(RED) {}
    };
int size;
Node* root;
    Node* insert(K key, Node* x);
    Node* rotateLeft(Node* x); 
    Node* rotateRight(Node* x);
    void flip(Node* x); 
public:
    LLRB();
    ~LLRB();
    void insert(K key);
    bool isRed(Node* x);    
};
#include "LLRB.cpp"
#endif
