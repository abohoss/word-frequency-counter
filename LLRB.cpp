#include "LLRB.hpp"

/* This is the constructor of the LLRB class. It initializes the root pointer to 0 (null) and the size to 0. */
template <typename K, typename V>
LLRB<K, V>::LLRB() : root(0), size(0) {}

/* `insert` function of the LLRB class. It takes a reference to a key (`K`) as a
parameter. */
template <typename K, typename V>
void LLRB<K, V>::insert(K &key)
{
    if (key == 0)
    {
        cerr << "no real key inserted!!" << endl;
        return:
    }
    root = insert(key, root);
}

/* The `insert` function is used to insert a key-value pair into the LLRB (Left-Leaning Red-Black) tree. */
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
        size++; // why????????????????
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
    treeNode->color = RED; // whyyyyyyyyyy
}

template <typename K, typename V>
void LLRB<K, V>::rotateLeft(LLRB<K, V>::Node *&treeNode)
{
    LLRB<K, V>::Node *temp = treeNode->right;
    treeNode->right = temp->left;
    temp->left = treeNode;
    temp->color = treeNode->color;
    treeNode->color = RED;
    return (treeNode);
}
template <typename K, typename V>
int LLRB<K, V>::size() const
{
    return (size);
}
template <typename K, typename V>
bool LLRB<K, V>::isEmpty() const
{
    return (this->root == NULL);
}

template <typename K, typename V>
V LLRB<K, V>::getFrequency(K &key) const
{
    if (key == NULL)
    {
        cerr << "*** Key must have a value (current Key is NULL) returning garbage value ***" << endl;
        V garbage;
        return (garbage);
    }
    return getFrequencyHelper(key, this->root);
}
template <typename K, typename V>
V LLRB<K, V>::getFrequencyHelper(K &key, LLRB<K, V>::Node *&treeNode) const
{
    if (this->isEmpty())
    {
        cerr << "***tree is empty returning a garbage value***" << endl;
        V garbage;
        return garbage;
    }
    if (key < treeNode->key)
    {
        return getFrequency(key, treeNode->left);
    }
    else if (key > treeNode->key)
    {
        return getFrequency(key, treeNode->right);
    }
    else
    {
        return treeNode->val;
    }
}

template <typename K, typename V>
void LLRB<K, V>::displayHelperRNL(ostream &out, LLRB<K, V>::Node *&treeNode) const
{
    if (treeNode != NULL)
    {
        displayHelperRNL(treeNode->right);
        out << treeNode->key << ": " << treeNode->value << '(' << treeNode->color << ')' << endl;
        displayHelperRNL(treeNode->left);
    }
}

template <typename K, typename V>
void LLRB<K, V>::displayHelperNLR(ostream &out, LLRB<K, V>::Node *&treeNode) const
{
    if (treeNode != NULL)
    {
        out << treeNode->key << ": " << treeNode->value << '(' << treeNode->color << ')' << endl;
        displayHelperNLR(treeNode->left);
        displayHelperNLR(treeNode->right);
    }
}

template <typename K, typename V>
void LLRB<K, V>::displayHelperLNR(ostream &out, LLRB<K, V>::Node *&treeNode) const
{
    if (treeNode != NULL)
    {
        displayHelperLNR(treeNode->left);
        out << treeNode->key << ": " << treeNode->value << '(' << treeNode->color << ')' << endl;
        displayHelperLNR(treeNode->right);
    }
}

template <typename K, typename V>
void LLRB<K, V>::display(ostream &out, unsigned short &choice) const
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
ostream &operator<<(ostream &out, const LLRB<K, V> &aLLRB)
{
    out << "press 1 for LNR, 2 for NLR, and 3 for NLR" << endl;
    unsigned short num;
    if (cin >> num)
    {
        display(out, num);
    }
    else
    {
        out << "***INVALID INPUT*** displaying default (NLR)" << endl;
        display(out);
    }
    return out;
}

template <typename K, typename V>
void LLRB<K, V>::erase(K key)
{
}

template class LLRB<string, int>;
template ostream &operator<<(ostream &out, const LLRB<string, int> &aLLRB);
