#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *items;
    int front, rear;
} Queue;
Queue* createQueue(int size)
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(size * sizeof(int));
    q->front = q->rear = 0;
    return q;
}
void enqueue(Queue* q, int value)
{
    q->items[q->rear++] = value;
}
int dequeue(Queue* q)
{
    return q->items[q->front++];
}
int isEmpty(Queue* q)
{
    return q->front == q->rear;
}
typedef struct Node
{
    int vertex;
    struct Node* next;
} Node;
Node* createNode(int v)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
typedef struct
{
    Node** adjList;
    int V;
} Graph;
Graph* createGraph(int V)
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++)
    {
        g->adjList[i] = NULL;
    }
    return g;
}
void addEdge(Graph* g, int src, int dest)
{
    Node* newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}
int shortestPath(Graph* g, int start, int end)
{
    if (start == end) return 0;
    int* dist = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++)
    {
        dist[i] = -1;
    }
    Queue* q = createQueue(g->V);
    dist[start] = 0;
    enqueue(q, start);
    while (!isEmpty(q))
    {
        int curr = dequeue(q);
        Node* temp = g->adjList[curr];
        while (temp)
        {
            int neighbor = temp->vertex;
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[curr] + 1;
                if (neighbor == end)
                {
                    int ans = dist[neighbor];
                    free(dist);
                    free(q->items);
                    free(q);
                    return ans;
                }
                enqueue(q, neighbor);
            }
            temp = temp->next;
        }
    }
    free(dist);
    free(q->items);
    free(q);
    return -1;
}
int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    Graph* g = createGraph(V);
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < E; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }
    int start, end;
    printf("Enter start and end vertices: ");
    scanf("%d %d", &start, &end);
    int result = shortestPath(g, start, end);
    if (result == -1)
    {
        printf("-1: No path exists.\n");
    }
    else
    {
        printf("Shortest path length: %d\n", result);
    }
    return 0;
}
