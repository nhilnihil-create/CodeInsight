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

ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
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

    ll n, x;
    cin >> n >> x;
    ll ans = 3 * (n - gcd(n, x));
    cout << ans;
    return 0;
}