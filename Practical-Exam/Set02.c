/*  [Practical Exam - 2025 : Set 02]
Write a program to take an undirected graph as input from the user and store it using
adjacency list (linked list) representations and print it. Then take two nodes X and Y as inputs
from user and check whether there is an edge between node X and Y.

Graph:     2-----3----4
            \   /
             \ /
              1

Test Cases: Enter two nodes: 1 and 3 → Output: Yes, there is an edge between node l and 3.
            Enter two nodes: 1 and 4 → Output: No, there is no edge between node 1 and 4.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

// Create new adjacency node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Print adjacency list
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Check edge between X and Y
void checkEdge(struct Graph* graph, int x, int y) {
    struct Node* temp = graph->adjList[x];
    while (temp != NULL) {
        if (temp->data == y) {
            printf("Yes, there is an edge between node %d and %d.\n", x, y);
            return;
        }
        temp = temp->next;
    }
    printf("No, there is no edge between node %d and %d.\n", x, y);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    int x, y;
    printf("\nEnter two nodes to check edge: ");
    scanf("%d %d", &x, &y);

    checkEdge(graph, x, y);

    return 0;
}