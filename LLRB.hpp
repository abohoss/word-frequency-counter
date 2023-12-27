#ifndef LLRB_HPP
#define LLRB_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "MaxPQ.hpp"
using namespace std;

enum Color
{
    RED,
    BLACK
};

class LLRB
{
private:
    class Node
    {
    public:
        Node *left;
        Node *right;
        int val;
        string key;
        Color color;
        Node(string key, int val) : left(NULL), right(NULL), val(val), key(key), color(RED){};
        Node(string key, int val, Color color) : left(NULL), right(NULL), val(val), key(key), color(color){};
    };
    long size;
    Node *root;
    void insert(string key, Node *&treeNode);
    void rotateLeft(Node *&treeNode);
    void rotateRight(Node *&treeNode);
    void flip(Node *&treeNode);
    bool isRed(Node *&treeNode);
    int getFrequencyHelper(string &key, Node *&treeNode);
    void displayHelperRNL(ostream &out, Node *&treeNode);
    void displayHelperNLR(ostream &out, Node *&treeNode);
    void displayHelperLNR(ostream &out, Node *&treeNode);
    void eraseHelper(string key, Node *&treeNode);
    void displayNfrequency(int n, Node *&treeNode);
    void eraseALL(Node *&treeNode);
    void copyTree(Node *&treeNodeOrig, Node *&treeNodeNew);
    void enqueueAll(Node *&treeNode, MaxPQ &PQ);
    void saveNode(Node *node, ofstream &file);
    Node *loadNode(ifstream &file, int& count);

public:
    LLRB();
    ~LLRB();
    LLRB(LLRB &origLLRB);
    LLRB &operator=(LLRB &rightLLRB);
    void insert(string &key);
    long getsize() const;
    bool isEmpty() const;
    int getFrequency(string &key);
    void display(ostream &out, int choice);
    void displayNfrequency(int n);
    void saveTree(const string &filename);
    void loadTree(const string &filename);
};

ostream &operator<<(ostream &out, LLRB &aLLRB);

#endif /* LLRB */
