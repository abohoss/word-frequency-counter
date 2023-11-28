#include "LLRB.hpp"
#include "MaxPQ.hpp"

/* This is the constructor of the LLRB class. It initializes the root pointer to 0 (null) and the size to 0. */
template <typename K, typename V>
LLRB<K, V>::LLRB() : root(0), size(0) {}

template <typename K, typename V>
void LLRB<K, V>::copyTree(LLRB<K, V>::Node *&originalNode, LLRB<K, V>::Node *&myRoot)
{
    if (originalNode == NULL)
        return;

    LLRB<K, V>::Node *newNode = new Node(originalNode->key, originalNode->val);
    newNode->color = originalNode->color;

    copyTree(originalNode->left, newNode->left);
    copyTree(originalNode->right, newNode->right);
}

template <typename K, typename V>
LLRB<K, V>::LLRB(LLRB<K, V> &origLLRB) : root(NULL), size(origLLRB.size)
{
    if (size == 0)
        return;

    copyTree(origLLRB.root, root);
}

template <typename K, typename V>
void LLRB<K, V>::eraseALL(LLRB<K, V>::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        eraseALL(treeNode->left);
        eraseALL(treeNode->right);
        delete treeNode;
    }
}

template <typename K, typename V>
LLRB<K, V>::~LLRB()
{
    eraseALL(root);
}

/* `insert` function of the LLRB class. It takes a reference to a key (`K`) as a
parameter. */
template <typename K, typename V>
void LLRB<K, V>::insert(K &key)
{
    if (key == "")
    {
        cerr << "no real key inserted!!" << endl;
        return;
    }
    insert(key, root);
}

/* The `insert` function is used to insert a key-val pair into the LLRB (Left-Leaning Red-Black) tree. */
template <typename K, typename V>
void LLRB<K, V>::insert(K key, LLRB<K, V>::Node *&treeNode)
{
    if (treeNode == 0)
    {
        size++;
        treeNode = new Node(key, 1);
    }
    if (key < treeNode->key)
    {
        insert(key, treeNode->left);
    }
    else if (key > treeNode->key)
    {
        insert(key, treeNode->right);
    }
    else
    {
        treeNode->val++;
    }
    if (isRed(treeNode->right) && !isRed(treeNode->left))
    {
        rotateLeft(treeNode);
    }
    if (isRed(treeNode->left) && isRed(treeNode->left->left))
    {
        rotateRight(treeNode);
    }
    if (isRed(treeNode->right) && isRed(treeNode->left))
    {
        flip(treeNode);
    }
}

template <typename K, typename V>
void LLRB<K, V>::flip(LLRB<K, V>::Node *&treeNode)
{
    if (treeNode == 0)
    {
        return;
    }
    treeNode->color = RED;
    treeNode->left->color = BLACK;
    treeNode->right->color = BLACK;
}

template <typename K, typename V>
bool LLRB<K, V>::isRed(LLRB<K, V>::Node *&treeNode) const
{
    return (treeNode->color == RED);
}

template <typename K, typename V>
void LLRB<K, V>::rotateRight(LLRB<K, V>::Node *&treeNode)
{
    LLRB<K, V>::Node *temp = treeNode->left;
    treeNode->left = temp->right;
    temp->right = treeNode;
    temp->color = treeNode->color;
    treeNode->color = RED;
}

template <typename K, typename V>
void LLRB<K, V>::rotateLeft(LLRB<K, V>::Node *&treeNode)
{
    LLRB<K, V>::Node *temp = treeNode->right;
    treeNode->right = temp->left;
    temp->left = treeNode;
    temp->color = treeNode->color;
    treeNode->color = RED;
}
template <typename K, typename V>
int LLRB<K, V>::getsize() const
{
    return (size);
}
template <typename K, typename V>
bool LLRB<K, V>::isEmpty() const
{
    return (this->root == NULL);
}

template <typename K, typename V>
V LLRB<K, V>::getFrequency(K &key)
{
    if (key == "")
    {
        cerr << "*** Key must have a val (current Key is NULL) returning garbage val ***" << endl;
        V garbage;
        return (garbage);
    }
    return getFrequencyHelper(key, this->root);
}
template <typename K, typename V>
V LLRB<K, V>::getFrequencyHelper(K &key, LLRB<K, V>::Node *&treeNode)
{
    if (this->isEmpty())
    {
        cerr << "***tree is empty returning a garbage val***" << endl;
        V garbage;
        return garbage;
    }
    if (key < treeNode->key)
    {
        return getFrequencyHelper(key, treeNode->left);
    }
    else if (key > treeNode->key)
    {
        return getFrequencyHelper(key, treeNode->right);
    }
    else
    {
        return treeNode->val;
    }
}

template <typename K, typename V>
void LLRB<K, V>::displayHelperRNL(ostream &out, LLRB<K, V>::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        displayHelperRNL(out, treeNode->right);
        out << treeNode->key << ": " << treeNode->val << endl;
        displayHelperRNL(out, treeNode->left);
    }
}

template <typename K, typename V>
void LLRB<K, V>::displayHelperNLR(ostream &out, LLRB<K, V>::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        out << treeNode->key << ": " << treeNode->val << endl;
        displayHelperNLR(out, treeNode->left);
        displayHelperNLR(out, treeNode->right);
    }
}

template <typename K, typename V>
void LLRB<K, V>::displayHelperLNR(ostream &out, LLRB<K, V>::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        displayHelperLNR(out, treeNode->left);
        out << treeNode->key << ": " << treeNode->val << endl;
        displayHelperLNR(out, treeNode->right);
    }
}

template <typename K, typename V>
void LLRB<K, V>::display(ostream &out, int choice)
{
    switch (choice)
    {
    case 1:
        out << "displaying LNR" << '\n'
            << endl;
        displayHelperLNR(out, this->root);
        break;

    case 2:
        out << "displaying NLR" << '\n'
            << endl;
        displayHelperNLR(out, this->root);
        break;

    case 3:
        out << "displaying RNL" << '\n'
            << endl;
        displayHelperRNL(out, this->root);
        break;
    }
}

template <typename K, typename V>
ostream &operator<<(ostream &out, LLRB<K, V> &aLLRB)
{
    out << "press 1 for LNR, 2 for NLR, and 3 for NLR" << endl;
    int num;
    if (cin >> num)
    {
        if (num >= 1 && num <= 3)
            aLLRB.display(out, num);
    }
    else
    {
        out << "***INVALID INPUT*** displaying default (NLR)" << endl;
        aLLRB.display(out, 2);
    }
    return out;
}

template <typename K, typename V>
void LLRB<K, V>::displayNfrequency(int n)
{
    displayNfrequency(n, root);
}

template <typename K, typename V>
 LLRB<K,V>& LLRB<K,V>::operator=( LLRB<K, V> &rightLLRB){

    this->size = rightLLRB->size;

    if(this->size == 0){
        this->~LLRB();
        this->root = NULL;
        return this;
    }
    if(this != &rightLLRB){
        this->~LLRB();
        this->root = rightLLRB->root;
        copyTree(rightLLRB,this);
    }

    return *this;

}

template <typename K, typename V>
void LLRB<K, V>::displayNfrequency(int n, LLRB<K, V>::Node *&treeNode)
{
    if (root == NULL)
    {
        cerr << "empty tree" << endl;
        return;
    }
    if (n > size)
    {
        cout << " cannot display more than your input! " << endl;
        return;
    }
    MaxPQ<V, K> PQ(size);
    cout << "TOP " << n << " frequenct words:  ";
    if (treeNode != NULL)
    {
        PQ.enqueue(treeNode->val, treeNode->key);
        displayNfrequency(n, treeNode->left);
        displayNfrequency(n, treeNode->right);
    }
    for (int i = 0; i < n; i++)
    {
        if (!PQ.isEmpty())
        {
            cout << PQ.getHighest()->val << "  its frequency: " << PQ.getHighest()->key << endl;
            PQ.dequeue();
        }
    }
    PQ.~MaxPQ();
}

template class LLRB<string, int>;
template ostream &operator<<(ostream &out, LLRB<string, int> &aLLRB);
