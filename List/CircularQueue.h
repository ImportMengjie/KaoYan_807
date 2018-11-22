//
// Created by mengjie on 11/22/18.
//

#ifndef DEMO_CIRCULARQUEUE_H
#define DEMO_CIRCULARQUEUE_H

#define MAX_LENGTH 5

class CircularQueue{
private:
    int *queue;
    int rear,front;

public:

    int length(){
        return (rear-front+MAX_LENGTH) % MAX_LENGTH;
    }

    CircularQueue(){
        queue = new int[MAX_LENGTH];
        rear = 0;
        front = 0;
    }

    bool isEmpty(){
        return rear==front;
    }

    bool enqueue(int e){
        if((rear+1)%MAX_LENGTH == front) return false;
        else{
            queue[rear] = e;
            rear = (rear+1)%MAX_LENGTH;
            return true;
        }
    }

    bool dequeue(){
        if(isEmpty()) return false;
        else{
            front = (front+1)%MAX_LENGTH;
            return true;
        }
    }

    bool dequeue(int &e){
        if(isEmpty()) return false;
        else{
            e = queue[front];
            front = (front+1)%MAX_LENGTH;
            return true;
        }
    }
};

#endif //DEMO_CIRCULARQUEUE_H
