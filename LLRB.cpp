#include "LLRB.hpp"

template <typename V,typename K>
LLRB<V,K>::LLRB(): root(0),size(0){}

template <typename V,typename K>
void LLRB<V,K>::insert(K key){
    if(key==0)  {
        cerr<<"no real key inserted!!"<<endl;
        return:
        }
    root=insert(key,root);
}


template <typename V,typename K>
Node* LLRB<V,K>::insert(K key,Node* x) {
    if(x==0) {
        size++;
        return new Node(key,1);
    }
    if(key < x->key) {x->left=insert(key,x->left);}
    else if(key > x->key) {x->right=insert(key,x->right);}
    else {  
        x->val++;
        size++;
    }
    if(isRed(x->right) && !isRed(x->left))  {rotateLeft(x);}
    if(isRed(x->left) && isRed(x->left->left))  {rotateRight(x);}
    if(isRed(x->right) && isRed(x->left))   {flip(x);}
    return x;
}
template <typename V,typename K>
void LLRB<V,K>::flip(Node* x){
    if(x==0) {return;}
    x->color=RED;
    x->left->color=BLACK;
    x->right->color=BLACK;
}
template <typename V,typename K>
bool LLRB<V,K>::isRed(Node* x){
    return x->color==RED;
}

template <typename V,typename K>

template <typename V,typename K>
