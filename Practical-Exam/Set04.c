/*  [Practical Exam - 2025 : Set 04]
Write a program to take an undirected graph as input from the user and store it using
adjacency list (linked list) representations and print it. Then take one node X as input from
user and print the degree of node X.
Note: The degree of any node is defined as the number of edges going from this node. Since,
the graph is undirected, number of incoming and outgoing edges are same. So, in this case, the
degree of the node is just the number of edges incident on this particular node.

Graph:     2-----3----4
            \   /
             \ /
              1

Test Cases: Enter one node: 1 → Output: Degree = 2.
Enter one node: 3 → Output: Degree = 3.
Enter one node: 4 → Output: Degree = 1.
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

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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

// Calculate degree of a node
int degreeOfNode(struct Graph* graph, int x) {
    int degree = 0;
    struct Node* temp = graph->adjList[x];
    while (temp != NULL) {
        degree++;
        temp = temp->next;
    }
    return degree;
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

    int x;
    printf("\nEnter one node: ");
    scanf("%d", &x);

    printf("Degree = %d\n", degreeOfNode(graph, x));

    return 0;
}