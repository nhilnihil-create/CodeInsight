#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

vector<bool> isVisited;
vector<vector<int>> neighbors;

void dfs(int node, vector<int>& result)
{
    isVisited[node] = true;
    result.push_back(node);

    for (int nxt : neighbors[node]) {
        if (!isVisited[nxt]) {
            dfs(nxt, result);
            break;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    isVisited.resize(n, false);
    neighbors.resize(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    vector<int> p1, p2;
    dfs(0, p1);
    dfs(0, p2);

    cout << p1.size() + p2.size() - 1 << endl;
    rrep(i, p1.size())
    {
        cout << p1[i] + 1 << " ";
    }
    rep(i, p2.size())
    {
        if (i != 0) {
            cout << p2[i] + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}