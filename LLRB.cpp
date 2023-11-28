#include "LLRB.hpp"
#include "MaxPQ.hpp"

/* This is the constructor of the LLRB class. It initializes the root pointer to 0 (null) and the size to 0. */
template <typename K, typename V>
LLRB<K, V>::LLRB() : root(0), size(0) {}

template <typename K, typename V>
LLRB<K, V>::Node *LLRB<K, V>::copyTree(LLRB<K, V>::Node *&currentNode, LLRB<K, V>::Node *&myRoot)
{
    if (currentNode == NULL)
        return;

    LLRB<K, V>::Node *newNode = new Node(currentNode->key, currentNode->value);
    newNode->color = currentNode->color;

    newNode->left = copyTree(currentNode->left, newNode);
    newNode->right = copyTree(currentNode->right, newNode);

    return newNode;
}

template <typename K, typename V>
LLRB<K, V>::LLRB(const LLRB &origLLRB) : root(NULL), size(origLLRB.size)
{
    if (size == 0)
        return;

    root = copyTree(origLLRB.root, NULL);
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
    if (key == 0)
    {
        cerr << "no real key inserted!!" << endl;
        return:
    }
    insert(key, root);
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
        out << treeNode->key << ": " << treeNode->value << endl;
        displayHelperRNL(treeNode->left);
    }
}

template <typename K, typename V>
void LLRB<K, V>::displayHelperNLR(ostream &out, LLRB<K, V>::Node *&treeNode) const
{
    if (treeNode != NULL)
    {
        out << treeNode->key << ": " << treeNode->value << endl;
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
        out << treeNode->key << ": " << treeNode->value << endl;
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
        if (num >= 1 && num <= 3)
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

// copy construdtor
template <typename K, typename V>
LLRB<K, V>::LLRB(const LLRB &origLLRB) : root(nullptr), size(origLLRB.size)
{
    if (size == 0)
        return;

    // Call the private helper function to copy the tree
    root = copyTree(origLLRB.root, nullptr);
}

template <typename K, typename V>
typename LLRB<K, V>::Node *LLRB<K, V>::copyTree(LLRB<K, V>::Node *&currentNode, LLRB<K, V>::Node *&parent)
{
    if (currentNode == NULL)
        return;

    // Create a new node with the same key, value, and color
    LLRB<K, V>::Node *newNode = new LLRB<K, V>::Node(currentNode->key, currentNode->value);
    newNode->color = currentNode->color;

    // Recursively copy the left and right subtrees
    newNode->left = copyTree(currentNode->left);
    newNode->right = copyTree(currentNode->right);

    return newNode;
}

template <typename K, typename V>
void LLRB<K, V>::displayNfrequency(int n)
{
    displayNfrequency(n, root);
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
    MaxPQ<K, V> PQ(size);
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

template class LLRB<string, unsigned short>;
template ostream &operator<<(ostream &out, const LLRB<string, unsigned short> &aLLRB);
