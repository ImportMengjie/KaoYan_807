//
// Created by mengjie on 11/19/18.
//

#ifndef DEMO_LIST_H
#define DEMO_LIST_H
class List{
protected:
    int len;

public:
    List(){
        len = 0;
    }
    virtual void initList() = 0;

    virtual int length(){
        return this->len;
    }

    virtual int locateElem(int e) = 0;

    virtual bool insert(int i, int e) = 0;

    virtual bool delete_(int i, int& e) = 0;

    virtual void printList() = 0;

    virtual bool empty() = 0;

};

#endif //DEMO_LIST_H
