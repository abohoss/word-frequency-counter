#ifndef MAX_HPP
#define MAX_HPP
#include <iostream>
#include <string>
using namespace std;
template <typename MaxKey, typename MaxVal>
class MaxPQ
{
private:
    class MaxNode
    {
    public:
        MaxKey key;
        MaxVal val;
        MaxNode(MaxKey key, MaxVal val) : key(key), val(val){};
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
    void enqueue(MaxKey key, MaxVal val);
    MaxNode *dequeue();
    MaxNode *getHighest();
    bool isEmpty() const;
    ~MaxPQ();
};
#endif
