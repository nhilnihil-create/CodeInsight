#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int MAX_N = 101000;
int n;
int pre[MAX_N], col[MAX_N];
vector<int> G[MAX_N];
int bfs()
{
    bool used[n + 1];
    memset(used, false, sizeof(used));
    queue<P> que;
    que.push(P(0, 0));
    while(!que.empty())
    {
        P p = que.front(); que.pop();
        int now = p.first;
        int cost = p.second;
        if(now == n - 1) return cost;
        if(used[now]) continue;
        used[now] = true;
        for(int next : G[now])
        {
            if(used[next]) continue;
            pre[next] = now;
            que.push(P(next, cost + 1));
        }
    }
}
void bfs2()
{
    int used[n + 1];
    memset(used, false, sizeof(used));
    queue<P> que;
    que.push(P(0, 0));
    while(!que.empty())
    {
        P p = que.front(); que.pop();
        int now = p.first;
        int cost = p.second;
        if(used[now]) continue;
        used[now] = true;
        col[now] = 1;
        for(int next : G[now])
        {
            if(used[next]) continue;
            if(col[next] == 2) continue;
            que.push(P(next, cost + 1));
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int num = bfs();
    int now = n - 1;
    int cnt = 0;
    while(1)
    {
        if(cnt < (num + 1) / 2) col[now] = 2;
        else col[now] = 1;
        cnt++;
        if(now == 0) break;
        now = pre[now];
    }
    bfs2();
    int f = 0;
    for(int i = 0; i < n; i++) if(col[i] == 1) f++;
    cout << (f > (n - f) ? "Fennec" : "Snuke") << endl;
    return 0;
}