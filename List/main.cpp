#include <iostream>
#include "CircularQueue.h"

using namespace std;
int main() {
    int temp = 0;
    CircularQueue queue;
    cout<<queue.isEmpty()<<endl;
    cout<<queue.length()<<endl;
    queue.enqueue(10);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.dequeue(temp);
    cout<<temp<<endl;
    queue.dequeue(temp);
    cout<<temp<<endl;
    queue.enqueue(2);
    queue.enqueue(2);
    cout<<queue.isEmpty()<<endl;
    cout<<queue.length()<<endl;


    return 0;
}