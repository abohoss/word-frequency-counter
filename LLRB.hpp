#ifndef LLRB
#define LLRB
#include <iostream>
using namespace std;

enum Color { RED, BLACK };
template <typename V,typename K>
class LLRB<V,K> {
private:
Node* root;
int size;
    class Node {
        Node* left,right;
        V val;
        K key;
        Color color;
        public:
        Node(K key, V val): left(NULL),right(NULL),val(val),key(key), color(RED) {}
    }
public:
    LLRB();
    ~LLRB();
    void insert(K key);
    bool isRed(Node* node);
private:
    Node* insert(K key, Node* node);
    void rotateLeft(Node* node); 
    void rotateright(Node* node);
    void flip(Node* node); 
};
#endif
