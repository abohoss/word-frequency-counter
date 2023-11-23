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
typename LLRB<V,k>::Node* LLRB<V,K>::insert(K key,Node* x) {
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
    if(isRed(x->right) && !isRed(x->left))  {x = rotateLeft(x);}
    if(isRed(x->left) && isRed(x->left->left))  {x = rotateRight(x);}
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
Node* LLRB<V,K>::rotateRight(Node* x) {
    typename LLRB<V,k>::Node* temp=x->left;
    x->left=temp->right;
    temp->right=x;
    temp->color=x->color;
    x->color=RED;
    return x;
}
template <typename V,typename K>
Node* LLRB<V,K>::rotateLeft(Node* x) {
    typename LLRB<V,k>::Node* temp=x->right;
    x->right=temp->left;
    temp->left=x;
    temp->color=x->color;
    x->color=RED;
    return x;
}
template <typename V,typename K>
int LLRV<V,K>::size(){
    return size;
}
template <typename V,typename K>
bool LLRB<V,K>::isEmpty(){
    return root == 0;
}

template class LLRB<int, string>;
