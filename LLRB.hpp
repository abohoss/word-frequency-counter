#ifndef LLRB
#define LLRB
#include <iostream>
#include <string>
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
    bool isRed(Node* x);  
    V getFrequency(K key, Node* x);
public:
    LLRB();
    ~LLRB();
    void insert(K key);
    int size();
    bool isEmpty();
    V getFrequency(K key);
};

#endif
