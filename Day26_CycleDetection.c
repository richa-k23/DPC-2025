#include <stdio.h>
#include <stdlib.h>
struct edge
{
    int src, dest;
};
int leader(int parent[], int i)
{
    if (parent[i] != i)
    {
        parent[i] = leader(parent, parent[i]);
    }
    return parent[i];
}
void unionSet(int parent[], int height[], int x, int y)
{
    int x_parent = leader(parent, x);
    int y_parent = leader(parent, y);
    if (height[x_parent] < height[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else if (height[x_parent] > height[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else
    {
        parent[y_parent] = x_parent;
        height[x_parent]++;
    }
}
int find_cycle(struct edge edges[], int V, int E)
{
    int *parent = (int *)malloc(V * sizeof(int));
    int *height = (int *)calloc(V, sizeof(int));
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        int x = leader(parent, edges[i].src);
        int y = leader(parent, edges[i].dest);
        if (x == y)
        {
            free(parent);
            free(height);
            return 1;
        }
        unionSet(parent, height, x, y);
    }
    free(parent);
    free(height);
    return 0;
}
int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct edge *edges = (struct edge *)malloc(E * sizeof(struct edge));
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &edges[i].src, &edges[i].dest);
    }
    if (find_cycle(edges, V, E))
    {
        printf("True: The graph contains a cycle.");
    }
    else
    {
        printf("False: The graph does not contain a cycle.");
    }
    free(edges);
    return 0;
}