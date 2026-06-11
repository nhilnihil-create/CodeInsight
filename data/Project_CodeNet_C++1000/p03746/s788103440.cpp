/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;

int n, m;

vector <int> edges[N_MAX];

bool used[N_MAX];

deque <int> path;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    path.push_back(1);
    used[1] = true;
    while(true)
    {
        bool ok = false;
        for(int v : edges[path.back()])
            if(used[v] == false)
            {
                path.push_back(v);
                used[v] = true;
                ok = true;
                break;
            }
        if(ok == false)
            break;
    }
    while(true)
    {
        bool ok = false;
        for(int v : edges[path.front()])
            if(used[v] == false)
            {
                path.push_front(v);
                used[v] = true;
                ok = true;
                break;
            }
        if(ok == false)
            break;
    }
    cout << path.size() << "\n";
    for(int u : path)
        cout << u << " ";
    cout << "\n";
    return 0;
}
