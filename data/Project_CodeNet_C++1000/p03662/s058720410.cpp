#include <iostream>
#include <vector>

using namespace std;

vector<int> adjacent[100'000];
bool visited[100'000];
bool onPath[100'000];
int dist[100'000];

void fill(const int node, const int end, const int d)
{
    visited[node] = true;
    dist[node] = d;
    if (node == end)
    {
        onPath[node] = true;
    }
    for (const int &adj : adjacent[node])
    {
        if (!visited[adj])
        {
            fill(adj, end, d + 1);
            onPath[node] = onPath[node] || onPath[adj];
        }
    }
}

bool visited2[100'000];

void countNodes(const int node, const int stop, int &count)
{
    visited2[node] = true;
    count++;

    for (const int &adj : adjacent[node])
    {
        if (!visited2[adj] && adj != stop)
        {
            countNodes(adj, stop, count);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
        onPath[i] = visited[i] = false;
    fill(0, N - 1, 0);

    int stop;
    for (int i = 0; i < N; i++)
    {
        if (onPath[i] && dist[i] - 1 + 1 == dist[N - 1] + 1 - (dist[N - 1] + 1) / 2)
        {
            stop = i;
        }
    }

    for (int i = 0; i < N; i++)
        visited2[i] = false;
    int cnt = 0;
    countNodes(0, stop, cnt);

    cout << (cnt > N - cnt ? "Fennec" : "Snuke") << endl;

    return 0;
}