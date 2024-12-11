#include <bits/stdc++.h>
using namespace std;

#define MAX 40

typedef struct queue {
    int data[MAX];
    int head, tail;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = -1;
    q->tail = -1;
    return q;
}

int isEmpty(Queue *q){
    if (q->tail == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *q, int data) {
    if (q->tail == MAX - 1) {
        cout<<"Queue is full!"<<endl;
    } else {
        if (q->head == -1)  {
            q->head = 0;
        }
        q->tail++;
        q->data[q->tail] = data;

    }
}

int dequeue(Queue *q) {
    int data;
    if (isEmpty(q)) {
        cout<<"Queue is empty!"<<endl;
        data = -1;
    } else {
        data = q->data[q->head];
        if (q->head+1  > q->tail) {
            q->head = q->tail = - 1;
        }
        q->head++;
    }
    return data;
}

void printQueue(Queue *q) {
    int i = q->head;
    if (isEmpty(q)) {
        cout<<"Queue is empty!"<<endl;
    } else {
        cout<<"Queue contains: :";
        for (int i = q->head; i <= q->tail; i++) {
            cout<<q->data[i]<<" ";
        }
    }
}


typedef struct edge {
    int data;
    struct edge *next;
} Edge;

typedef struct edgeList {
    Edge *head;
} EdgeList;

typedef struct graph {
    int numOfVertex;
    int* visited;
    EdgeList *array;
} Graph;

Edge *createEdge(int data) {
    Edge *temp = (Edge *)malloc(sizeof(Edge));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Graph *createGraph(int numV) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numOfVertex = numV;
    g->array = (EdgeList *)malloc(numV * sizeof(EdgeList));
    g->visited = (int*)malloc(numV * sizeof(int));
    for (int i = 0; i < numV; i++) {
        g->array[i].head = NULL;
        g->visited[i] = 0;
    }
    return g;
}

void addEdge(Graph *g, int src, int dest) {
    Edge *temp = createEdge(dest);
    temp->next = g->array[src].head;
    g->array[src].head = temp;

    temp = createEdge(src);
    temp->next = g->array[dest].head;
    g->array[dest].head = temp;
}

void printGraph(Graph *g) {
    cout<<"Adjaceny Graph Representation: "<<endl;
    for (int i = 0; i < g->numOfVertex; i++) {
        cout<<"Vertex "<<i<<": ";
        Edge *temp = g->array[i].head;
        while (temp) {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void bfs(Graph *g, int start) {
    Queue *q = createQueue();
    g->visited[start] = 1;
    enqueue(q, start);
    while (!isEmpty(q)) {
        printQueue(q);
        int current = dequeue(q);
        cout<<"Visited: "<<current<<endl;
        Edge *temp = g->array[current].head;
        while (temp) {
            int adj = temp->data;
            if(g->visited[adj] == 0) {
                g->visited[adj] = 1;
                enqueue(q, adj);
            }
            temp = temp->next;
        }
    }
}


int main() {

    Graph *g = createGraph(6);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 4);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);

    printGraph(g);

    bfs(g, 0);

    return 0;
}