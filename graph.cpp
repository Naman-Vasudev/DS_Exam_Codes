#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

// ---------------------------------------------------------------
// ORIGINAL GRAPH CLASS (UNTOUCHED)
// ---------------------------------------------------------------
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void add_edge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print_adjacency_list()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int neighbor : l[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    void print_adjacency_matrix()
    {
        cout << "Adjacency Matrix:" << endl;
        vector<vector<int>> matrix(V, vector<int>(V, 0));
        
        for (int i = 0; i < V; i++)
        {
            for (int j : l[i])
            {
                matrix[i][j] = 1;
            }
        }
        
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs()
    {
        queue<int> q;
        vector<bool> vis(V, false);

        vis[0] = true;
        q.push(0);
        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfs()
    {
        vector<bool> vis(V, false);
        stack<int> s;

        vis[0] = true;
        s.push(0);

        while (!s.empty())
        {
            int u = s.top();
            s.pop();

            cout << u << " ";

            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    s.push(v);
                }
            }
        }
        cout << endl;
    }
};

// ---------------------------------------------------------------
// NEW CLASS: WEIGHTED GRAPH + DIJKSTRA
// ---------------------------------------------------------------
class WeightedGraph
{
    int V;
    list<pair<int, int>> *adj; // (neighbor, weight)

public:
    // DIFFERENT CONSTRUCTOR
    WeightedGraph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    // Weighted add_edge
    void add_edge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra implementation
    vector<int> dijkstra(int src)
    {
        vector<int> dist(V, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

// ---------------------------------------------------------------
// MAIN
// ---------------------------------------------------------------
int main()
{
    // ORIGINAL GRAPH (UNTOUCHED)
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    cout << "Adjacency List:" << endl;
    g.print_adjacency_list();

    cout << "BFS: ";
    g.bfs();

    cout << "DFS: ";
    g.dfs();

    // -------------------------------------
    // SECOND OBJECT: WEIGHTED GRAPH + DIJKSTRA
    // -------------------------------------
    WeightedGraph wg(5);
    wg.add_edge(0, 1, 2);
    wg.add_edge(0, 4, 5);
    wg.add_edge(1, 2, 3);
    wg.add_edge(1, 3, 1);
    wg.add_edge(2, 3, 8);
    wg.add_edge(3, 4, 4);

    cout << "\nDijkstra (source = 0):\n";
    vector<int> dist = wg.dijkstra(0);

    for (int i = 0; i < dist.size(); i++)
    {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}
