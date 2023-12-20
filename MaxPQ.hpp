#ifndef MAX_HPP
#define MAX_HPP
#include <iostream>
#include <string>
using namespace std;

class MaxPQ
{
private:
    class MaxNode
    {
    public:
        int key;
        string val;
        MaxNode(int key, string val) : key(key), val(val){};
    };
    MaxNode **arr;
    int capacity;
    int size;
    void swap(MaxNode *x, MaxNode *y);
    int leftchild(int i);
    int rightchild(int i);
    int parent(int i);
    void swim(int i);
    void sink(int i);

public:
    MaxPQ(int capacity)
    {
        arr = new MaxNode *[capacity];
        if (arr == NULL)
        {
            cerr << "memory allocation failed" << endl;
            exit(1);
        }
        this->capacity = capacity;
        size = 1;
    }
    void enqueue(int key, string val);
    void dequeue();
    MaxNode *getHighest();
    bool isEmpty() const;
    ~MaxPQ();
    void display();
};
#endif
