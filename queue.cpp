// Queue Data structure implementation using c++
// This circular queue
#include <iostream>
#define MAX 5

using namespace std;

typedef struct queue {
    int data[MAX+1];
    int head, tail;
} Queue;

void enqueue(Queue *q, int data) {
    if ((q->tail+1)%(MAX+1) == q->head) {
        cout<<"Queue is Full!"<<endl;
    } else {
        q->data[q->tail] = data;
        q->tail = (q->tail+1)%(MAX+1);
    }
}

int dequeue(Queue *q) {
    int a;
    if (q->tail == q->head) {
        cout<<"Queue is Empty ";
        return -1;
    } else {
        a = q->data[q->head];
        q->head = (q->head+1) % (MAX+1);
    }
    return a;
}

int main() {
    Queue my;
    my.head = 0;
    my.tail = 0;
    int a;

    enqueue(&my, 11);
    enqueue(&my, 22);
    enqueue(&my, 33);
    enqueue(&my, 44);
    enqueue(&my, 55);
    

    a = dequeue(&my);
    cout<<a<<endl;

    a = dequeue(&my);
    cout<<a<<endl;

    a = dequeue(&my);
    cout<<a<<endl;

    a = dequeue(&my);
    cout<<a<<endl;

    a = dequeue(&my);
    cout<<a<<endl;

    

    enqueue(&my, 88);
    
    a = dequeue(&my);
    cout<<a<<endl;


    return 0;
}