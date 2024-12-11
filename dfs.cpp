#include <bits/stdc++.h>
using namespace std;

typedef struct edge {
    int data;
    struct edge *next;
} Edge;

typedef struct edgeList {
    Edge *head;
} EdgeList;

typedef struct graph {
    int numV;
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
    g->numV = numV;
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
    cout<<"Adjacency graph representation with linked list: "<<endl;
    for (int i = 0; i < g->numV; i++)  {
        Edge *temp = g->array[i].head;
        cout<<"Vertex "<<i<<" :";
        while (temp){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void dfs(Graph *g, int start){
    Edge *temp = g->array[start].head;
    g->visited[start] = 1;
    cout<<start<<" ";
    while (temp != NULL) {
        int connectedVertex = temp->data;
        if (g->visited[connectedVertex] == 0) {
            dfs(g, connectedVertex);
        }
        temp = temp->next;
    }
}
int main() {
    Graph *g = createGraph(6);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 3);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 5);
    addEdge(g, 3, 4);
    addEdge(g, 4, 1);
    addEdge(g, 4, 5);

    printGraph(g);

    cout<<"Visited DFS: ";
    dfs(g, 1);

    cout<<endl;

    return 0;
}