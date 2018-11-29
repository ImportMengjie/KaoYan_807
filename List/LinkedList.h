//
// Created by mengjie on 11/19/18.
//

#ifndef DEMO_LINKEDLIST_H
#define DEMO_LINKEDLIST_H

#include "List.h"

struct Node{
   Node *pNext;
   Node *pPre;
   int data;
};

class LinkedList:public List{
private:
    Node *head;
public:

    LinkedList() = default;

    void initList() override {

    }

    int locateElem(int e) override {
        return 0;
    }

    bool insert(int i, int e) override {
        return false;
    }

    bool delete_(int i, int &e) override {
        return false;
    }

    void printList() override {

    }

    bool empty() override {
        return false;
    }

};

#endif //DEMO_LINKEDLIST_H
