#include <iostream>
using namespace std;
#define V 7
#define INF 99999

int minDist(int dist[], bool sptSet[])
{
    int min = INF, min_idx;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_idx = v;
 
    return min_idx;
}

void printDist(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
 
    bool sptSet[V];
 
    for (int i = 0; i < V; i++){
          dist[i] = INF;
          sptSet[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {

        int u = minDist(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];        
        }
    }
    printDist(dist);    
}
 
int main()
{
    int inputGraph[V][V] = {    { 0, 6, 0, 0, 0, 3, 0},
                                { 6, 0, 9, 0, 0, 0, 0},
                                { 0, 9, 0, 8, 0, 0, 12},
                                { 0, 0, 8, 4, 0, 0, 0},
                                { 0, 0, 0, 4, 0, 7, 3},
                                { 3, 0, 0, 0, 7, 0, 10},
                                { 0, 14, 12, 0, 3, 10, 0}
                            };
 
    dijkstra(inputGraph, 0);
    return 0;
}