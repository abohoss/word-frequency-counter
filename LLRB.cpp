#include "LLRB.hpp"
#include "MaxPQ.hpp"

/* This is the constructor of the LLRB class. It initializes the root pointer to 0 (null) and the size to 0. */

LLRB::LLRB() : root(0), size(0) {}


void LLRB::copyTree(LLRB::Node *&originalNode, LLRB::Node *&myRoot)
{
    if (originalNode == NULL)
        return;

    LLRB::Node *newNode = new Node(originalNode->key, originalNode->val);
    newNode->color = originalNode->color;

    copyTree(originalNode->left, newNode->left);
    copyTree(originalNode->right, newNode->right);
}


LLRB::LLRB(LLRB &origLLRB) : root(NULL), size(origLLRB.size)
{
    if (size == 0)
        return;

    copyTree(origLLRB.root, root);
}


void LLRB::eraseALL(LLRB::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        eraseALL(treeNode->left);
        eraseALL(treeNode->right);
        delete treeNode;
    }
}


LLRB::~LLRB()
{
    eraseALL(root);
    root = NULL;
}

/* `insert` function of the LLRB class. It tastringes a reference to a key (`string`) as a
parameter. */

void LLRB::insert(string &key)
{
    if (key == "")
    {
        cerr << "no real key inserted!!" << endl;
        return;
    }
    insert(key, root);
}

/* The `insert` function is used to insert a key-val pair into the LLRB (Left-Leaning Red-Blacstring) tree. */

void LLRB::insert(string key, LLRB::Node *&treeNode)
{
    if (treeNode == 0)
    {
        size++;
        treeNode = new Node(key, 1);
        return;
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


void LLRB::flip(LLRB::Node *&treeNode)
{
    if (treeNode == 0)
    {
        return;
    }
    treeNode->color = RED;
    treeNode->left->color = BLACK;
    treeNode->right->color = BLACK;
}


bool LLRB::isRed(LLRB::Node *&treeNode)
{
    if (treeNode == NULL)
        return false;

    return (treeNode->color == RED);
}


void LLRB::rotateRight(LLRB::Node *&treeNode)
{
    LLRB::Node *temp = treeNode->left;
    treeNode->left = temp->right;
    temp->right = treeNode;
    temp->color = treeNode->color;
    treeNode->color = RED;
    treeNode = temp;
}


void LLRB::rotateLeft(LLRB::Node *&treeNode)
{
    LLRB::Node *temp = treeNode->right;
    treeNode->right = temp->left;
    temp->left = treeNode;
    temp->color = treeNode->color;
    treeNode->color = RED;
    treeNode = temp;
}

int LLRB::getsize() const
{
    return (size);
}

bool LLRB::isEmpty() const
{
    return (this->root == NULL);
}


int LLRB::getFrequency(string &key)
{
    if (key == "")
    {
        cerr << "*** key must have a val (current key is NULL) returning garbage val ***" << endl;
        int garbage = -1;
        return (garbage);
    }
    return getFrequencyHelper(key, this->root);
}

int LLRB::getFrequencyHelper(string &key, LLRB::Node *&treeNode)
{
    if (this->isEmpty())
    {
        cerr << "***tree is empty returning a garbage val***" << endl;
        int garbage = -1;
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


void LLRB::displayHelperRNL(ostream &out, LLRB::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        displayHelperRNL(out, treeNode->right);
        out << treeNode->key << ": " << treeNode->val << endl;
        displayHelperRNL(out, treeNode->left);
    }
}


void LLRB::displayHelperNLR(ostream &out, LLRB::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        out << treeNode->key << ": " << treeNode->val << endl;
        displayHelperNLR(out, treeNode->left);
        displayHelperNLR(out, treeNode->right);
    }
}


void LLRB::displayHelperLNR(ostream &out, LLRB::Node *&treeNode)
{
    if (treeNode != NULL)
    {
        displayHelperLNR(out, treeNode->left);
        out << treeNode->key << ": " << treeNode->val << endl;
        displayHelperLNR(out, treeNode->right);
    }
}


void LLRB::display(ostream &out, int choice)
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


ostream &operator<<(ostream &out, LLRB &aLLRB)
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


void LLRB::displayNfrequency(int n)
{
    MaxPQ PQ(size * 2);
    displayNfrequency(n, root, PQ);
}




void LLRB::displayNfrequency(int n, LLRB::Node *&treeNode, MaxPQ PQ)
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

    if (treeNode != NULL)
    {
        PQ.enqueue(treeNode->val, treeNode->key);
        displayNfrequency(n, treeNode->left, PQ);
        displayNfrequency(n, treeNode->right, PQ);
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


