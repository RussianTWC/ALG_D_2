#include <stdio.h>
#include <limits.h>

#define CountVertices 9


typedef struct Path {
    int Dist[CountVertices];
    int Visited[CountVertices];
} Path;

void Algorithm_Dijkstra(int graph[CountVertices][CountVertices], int StartVertice);

int main() {
    int graph[CountVertices][CountVertices] = {
{0, 3, 0, 0, 8, 4, 0, 0, 0},
 {0, 2, 8, 0, 7, 0, 0, 0, 0},
 {0, 0, 4, 7, 0, 12, 0, 6, 0},
 {0, 0, 0, 0, 12, 0, 9, 0, 2},
 {0, 0, 0, 0, 0, 9, 0, 1, 0},
 {0, 5, 0, 0, 6, 0, 1, 0, 11},
 {0, 0, 0, 0, 0, 2, 0, 11, 0 }
    };

    Algorithm_Dijkstra(graph, 0);

    return 0;
}


void Algorithm_Dijkstra(int graph[CountVertices][CountVertices], int StartVertice) {
    Path path;
    for (int i = 0; i < CountVertices; i++) {
        path.Dist[i] = INT_MAX;
        path.Visited[i] = 0;
    }
    path.Dist[StartVertice] = 0;

    int pq[CountVertices];
    int pq_size = 0;
    pq[pq_size++] = StartVertice;

    while (pq_size > 0) {
        int min_dist = INT_MAX, min_index = -1;
        for (int i = 0; i < pq_size; i++) {
            if (path.Dist[pq[i]] < min_dist) {
                min_dist = path.Dist[pq[i]];
                min_index = i;
            }
        }
        int U = pq[min_index];
        pq[min_index] = pq[--pq_size];

        if (path.Visited[U]) {
            continue;
        }

        path.Visited[U] = 1;

        for (int V = 0; V < CountVertices; V++) {
            if (!path.Visited[V] && graph[U][V] && path.Dist[U] != INT_MAX && path.Dist[U] + graph[U][V] < path.Dist[V]) {
                path.Dist[V] = path.Dist[U] + graph[U][V];
                int j;
                for (j = 0; j < pq_size; j++) {
                    if (pq[j] == V) {
                        break;
                    }
                }
                if (j == pq_size) {
                    pq[pq_size++] = V;
                }
            }
        }
    }

    printf("Vertice \t Distance from Source\n");
    for (int i = 0; i < CountVertices; i++) {
        printf("%d \t\t %d\n", i, path.Dist[i]);
    }
}

