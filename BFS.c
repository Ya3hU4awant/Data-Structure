
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

// Breadth First Search
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int vertex, i;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int edges, i, j, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    // Initialize graph and visited array
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > n * (n - 1) / 2)
    {
        printf("Invalid number of edges.\n");
        return 1;
    }

    // Input edges
    printf("Enter edges (u v), using vertices 0 to %d:\n", n - 1);

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n || u == v)
        {
            printf("Invalid edge. Try again.\n");
            i--;
            continue;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    printf("BFS Traversal: ");

    BFS(start);

    // Visit disconnected components
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS(i);
        }
    }

    printf("\n");

    return 0;
}
