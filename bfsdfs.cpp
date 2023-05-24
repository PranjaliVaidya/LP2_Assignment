#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
public:
    vector<vector<int>> adj;   //adj dynamic array no need to give size of adj
    Graph(int n)
    {
        adj.resize(n);
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void BFS(Graph const &graph, queue<int> &q, vector<bool> &discovered)
    {
        if (q.empty())
        {
            return;
        }
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : graph.adj[v])
        {
            if (!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
        }

        BFS(graph, q, discovered);
    }

    void DFS(Graph const &graph, int v, vector<bool> &discovered)
    {
        discovered[v] = true;
        cout << v << " ";

        for (int u : graph.adj[v])
        {
            if (!discovered[u])
            {
                DFS(graph, u, discovered);
            }
        }
    }
};

int main()
{
    int n, a, b;
    vector<vector<int>> v;
    cout << "Enter number of vertices : " << endl;
    cin >> n;
    Graph g(n);
    cout << "ENter the number of edges : " << endl;
    int x;
    cin>>x;
    cout << "ENter the edges : " << endl;
    
    for (int i = 0; i < x; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    queue<int> q;
    vector<bool> discovered(n, false);
    for (int i = 0; i < n; i++)
    {
        if (discovered[i] == false)
        {
            discovered[i]=true;
            q.push(i);
            g.BFS(g, q, discovered);
        }
    }
    cout << endl;
    vector<bool> discovered1(n, false);
    for (int i = 0; i < n; i++)
    {
        if (discovered1[i] == false)
        {
            g.DFS(g, i, discovered1);
        }
    }

    return 0;
}