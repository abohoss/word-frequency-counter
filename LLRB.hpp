#ifndef LLRB_HPP
#define LLRB_HPP
#include <iostream>
#include <string>
using namespace std;

enum Color
{
    RED,
    BLACK
};
template <typename K, typename V>
class LLRB
{
private:
    class Node
    {
    public:
        Node *left;
        Node *right;
        V val;
        K key;
        Color color;
        Node(K key, V val) : left(NULL), right(NULL), val(val), key(key), color(RED){};
    };
    int size;
    Node *root;
    void insert(K key, Node *&treeNode);
    void rotateLeft(Node *&treeNode);
    void rotateRight(Node *&treeNode);
    void flip(Node *&treeNode);
    bool isRed(Node *&treeNode) const;
    V getFrequencyHelper(K &key, Node *&treeNode);
    void displayHelperRNL(ostream &out, LLRB<K, V>::Node *&treeNode) const;
    void displayHelperNLR(ostream &out, LLRB<K, V>::Node *&treeNode) const;
    void displayHelperLNR(ostream &out, LLRB<K, V>::Node *&treeNode) const;
    void eraseHelper(K key, LLRB<K, V>::Node *&treeNode);
    void displayNfrequency(int n, LLRB<K, V>::Node *&treeNode);
    void eraseALL(LLRB<K, V>::Node *&treeNode);
    Node *copyTree(Node *&treeNodeOrig, Node *&treeNodeNew);

public:
    LLRB();
    ~LLRB();
    LLRB(LLRB &origLLRB);
    void insert(K &key);
    int getsize() const;
    bool isEmpty() const;
    V getFrequency(K &key);
    void display(ostream &out, unsigned short &choice = 2) const;
    void displayNfrequency(int n);
};

template <typename K, typename V>
ostream &operator<<(ostream &out, const LLRB<K, V> &aLLRB);

#endif /* LLRB */
