#include <bits/stdc++.h>
#include <math.h>
#include <list>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
void sor(vector<ll> &x)
{
    sort(x.begin(), x.end());
}

list<ll> a[5];
void bfs(int src)
{
    queue<int> q;
    bool *vis = new bool[5 + 1]{0};
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int n : a[node])
        {
            if (!vis[n])
            {
                q.push(n);
                vis[n] = true;
            }
        }
    }
}

ll min(ll x, ll y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int main()
{

    int n;
    cin >> n;
    vector<ll> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < 2 * n; i += 2)
    {
        ans += a[i];
    }
    cout << ans;
    return 0;
}