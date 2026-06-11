#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <assert.h>
#include <cstdio>

// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

inline bool chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

inline bool chmax(ll &a, ll b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

//桁数取得
template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}
//整数乗
ll llpow(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        ll rep = a;
        for (ll i = 1; i < n; i++)
        {
            rep *= a;
        }
        return rep;
    }
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

template <typename T>
T amarinasi(T a, T b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else if (a % b > 0)
    {
        return a / b + 1;
    }
    else
    {
        return a / b - 1;
    }
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------
const double pi = 3.14159265358979323846264;

struct edge
{
    ll to, cost;
};
typedef pair<ll, ll> P;
struct graph
{
    ll V;
    vector<vector<edge>> G;
    vector<ll> d;

    graph(ll n)
    {
        init(n);
    }

    void init(ll n)
    {
        V = n;
        G.resize(V);
        d.resize(V);
        for (ll i = 0; i < V; i++)
        {
            d[i] = INF;
        }
    }

    void add_edge(ll s, ll t, ll cost)
    {
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(ll s)
    {
        for (ll i = 0; i < V; i++)
        {
            d[i] = INF;
        }
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(P(0, s));
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            ll v = p.second;
            if (d[v] < p.first)
                continue;
            for (auto e : G[v])
            {
                if (d[e.to] > d[v] + e.cost)
                {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }
};

vector<vector<ll>> g(210, vector<ll>());
int main()
{
    ll n, m, r;
    cin >> n >> m >> r;
    graph g(n);
    ll machi[r];
    for (ll i = 0; i < r; i++)
    {
        cin >> machi[i];
        machi[i]--;
    }
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a - 1, b - 1, c);
        g.add_edge(b - 1, a - 1, c);
    }
    ll ans = infll;
    vector<vector<ll>> dist(210, vector<ll>(210, infll));
    for (ll i = 0; i < r; i++)
    {
        g.dijkstra(machi[i]);
        for (ll j = 0; j < r; j++)
        {
            if (i == j)
            {
                continue;
            }
            dist[machi[i]][machi[j]] = g.d[machi[j]];
        }
    }
    vector<ll> nums(r);
    iota(nums.begin(), nums.end(), 0);
    do
    {
        ll tmp = 0;
        for (ll i = 0; i < r - 1; i++)
        {
            tmp += dist[machi[nums[i]]][machi[nums[i + 1]]];
        }
        chmin(ans, tmp);
    } while (next_permutation(nums.begin(), nums.end()));
    cout << ans << endl;
}
