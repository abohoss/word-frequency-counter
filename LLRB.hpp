#ifndef LLRB
#define LLRB
#include <iostream>
using namespace std;
template <typename V,typename K>

class LLRB<V,K> {
private:
Node* root;
    class Node {
        Node* left,right;
        V val;
        K key;
        int size;
        public:
        Node(K key, V val, int size): left(0),right(0),val(val),key(key),size(size) {}
    }
public:
    LLRB();
    ~LLRB();
    
};
#endif
