// Stack implementation using c++
#include <iostream>
#define MAX 5
using namespace std;

typedef struct stack {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int data) {
    if (s->top < MAX) {
        s->data[s->top] = data;
        s->top++;
    } else {
        cout<<"Stack is full!"<<endl;
    }
}

int pop(Stack *s) {
    int a;
    if (s->top == 0) {
        cout<<"Stack is Empty ";
        return -1;
    } else {
        s->top--;
        a = s->data[s->top];
    }
    return a;
}

int main() {
    int a;
    Stack my;
    my.top = 0;

    push(&my, 10);
    push(&my, 20);
    push(&my, 30);
    push(&my, 40);
    push(&my, 50);

    a = pop(&my);
    cout<<a<<endl;

    a = pop(&my);
    cout<<a<<endl;

    a = pop(&my);
    cout<<a<<endl;

    a = pop(&my);
    cout<<a<<endl;

    a = pop(&my);
    cout<<a<<endl;

    return 0;
}