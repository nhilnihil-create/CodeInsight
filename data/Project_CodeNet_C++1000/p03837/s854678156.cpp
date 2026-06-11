#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<unordered_set>
#include<map>




using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

class Graph {
    int V;
    vector<vector<pair<int, int> > > adjList;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int floyd_warshall(int u,int v);

};

Graph::Graph(int V)
{
    adjList = vector<vector<pair<int, int> > >(V);
    this->V = V;
}


void Graph::addEdge(int u, int v, int w)
{
    adjList[u].push_back(pair<int, int>(v, w));
    adjList[v].push_back(pair<int, int>(u, w));
}

int Graph::floyd_warshall(int u,int v)
{
    vector<vector<int> > dist(V);
    int i,j,k;
    
    for (i = 0; i < V; ++i) {
        dist[i] = vector<int>(V);
    }
    for (i = 0; i < V; ++i) {
        for (j = 0; j < V; ++j) {
            dist[i][j] = 0x3f3f3f;//infinity
        }
    }
    for (i = 0; i < V; ++i) {
        dist[i][i] = 0;
    }
    for (i = 0; i < V; ++i) {
        for (j = 0; j < adjList[i].size(); ++j) {
            dist[i][adjList[i][j].first] = adjList[i][j].second;
        }
    }

    for (k = 0; k < V; ++k) {
        for (i = 0; i < V; ++i) {
            for (j = 0; j < V; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int count = 0;
    for (i = 0; i < V; ++i) {
        for (j = 0; j < adjList[i].size(); ++j) {
            if (dist[i][adjList[i][j].first] != adjList[i][j].second) {
                count++;
            }
        }
    }

    return count/2;

}




int main() {
    int n, m, x;
    cin >> n >> m;
    Graph g(n);
    int i,a,b,w;
    for (i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        --a, --b;
        g.addEdge(a, b, w);
    }
    
    cout << g.floyd_warshall(0,4);
    

}
  