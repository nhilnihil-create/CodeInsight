#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

//Weighted edge set
template <typename T>
using Edges = vector<edge<T>>;

//Weighted graph
template <typename T>
using WeightedGraph = vector<Edges<T>>;

//Unweighted graph (adjacency matrix)
//Initialize : vector<vector<int>>(N, vector<int>(N, 0))
template <typename T>
using UnweightedGraph = vector<vector<T>>;

//distance matrix
template <typename T>
using Matrix = vector<vector<T>>;

int N;
UnweightedGraph<int> G;
vector<bool> visited;
vector<char> color;

void bfs()
{
    queue<pair<int, char>> que;
    que.emplace(0, 'B');
    que.emplace(N - 1, 'W');
    while (!que.empty())
    {
        auto p = que.front();
        int now = p.first;
        char c = p.second;
        que.pop();
        if (visited[now] == true)
            continue;
        visited[now] = true;
        color[now] = c;
        for (auto &e : G[now])
        {
            if (visited[e] == false)
                que.emplace(e, c);
        }
    }
}

int main()
{
    cin >> N;
    G = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    color = vector<char>(N);
    color[0] = 'B', color[N - 1] = 'W';
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs();
    int b = 0, w = 0;
    for (int i = 0; i < N; i++)
    {
        if (color[i] == 'B')
            b++;
        else
            w++;
    }
    if (w >= b)
        cout << "Snuke" << endl;
    else
        cout << "Fennec" << endl;
}