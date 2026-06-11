#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>
#include <unordered_map>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define ALL(v) v.begin(), v.end()

struct edge
{
    ll from, to, cost;
};
edge es[2005]; // 辺
ll d[1005];    // 最短距離
ll V, E;        // 頂点数･辺数

/* デカい配列はここで宣言 */

int main(int argc, char const *argv[])
{
    cin >> V >> E;
    for (ll i = 0; i < E; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        es[i].from = a - 1;
        es[i].to = b - 1;
        es[i].cost = -c;
    }

    ll s = 0;
    for (ll i = 0; i < V; i++)
        d[i] = LLONG_MAX;
    d[s] = 0;
    for (ll k = 0; k < V - 1; k++)
    {
        for (ll i = 0; i < E; i++)
        {
            edge e = es[i];
            if (d[e.from] != LLONG_MAX && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }

    ll ans = d[V - 1];

    bool negative[1005] = {false};
    for (ll i = 0; i < 1005; i++)
    {
        negative[i] = false;
    }

    for (ll k = 0; k < V; k++)
    {
        for (ll i = 0; i < E; i++)
        {
            edge e = es[i];

            if (d[e.from] == LLONG_MAX)
                continue;

            if (d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                negative[e.to] = true;
            }

            if (negative[e.from])
            {
                negative[e.to] = true;
            }
        }
    }

    if (negative[V - 1])
        cout << "inf" << endl;
    else
    {
        cout << -ans << endl;
    }
}