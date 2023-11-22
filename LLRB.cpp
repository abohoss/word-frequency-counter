#include "LLRB.hpp"
template <typename V,typename K>
LLRB<V,K>::LLRB(){
    root=0;
    size=0;
}
template <typename V,typename K>
void LLRB<V,K>::insert(K key){
    if(key==0)  {
        cerr<<"no real key inserted!!"<<endl;
        return:
        }
    root=insert(key,root);
}





template <typename V,typename K>
template <typename V,typename K>
template <typename V,typename K>