#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount __builtin_popcount
#define flag(x) (1ll << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1ll << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));
/*
全頂点対最短距離を求める
※必ずwarshall_floyd_init(V, dist);を記述した後入力を受け取らないとバグります...
dist[i][i]<0なら負閉路あり
dist[i][j]==1e18ならi->jの経路を持たない
計算量O(V^3)
*/
void warshall_floyd_init(long long V, vector<vector<long long>> &dist)
{
    //初期化
    for (long long i = 0; i < V; i++)
    {
        for (long long j = 0; j < V; j++)
        {
            if (i == j)
                dist[i].push_back(0);
            else
                dist[i].push_back(1e18);
        }
    }
}
void warshall_floyd(long long V, vector<vector<long long>> &dist)
{
    for (long long k = 0; k < V; k++)
    {
        for (long long i = 0; i < V; i++)
        {
            for (long long j = 0; j < V; j++)
            {
                if (dist[i][k] != 1e18 && dist[k][j] != 1e18)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main()
{
    cout << fixed << setprecision(30);
    ll N, M;
    cin >> N >> M;
    vector<vector<long long>> dist(N);
    warshall_floyd_init(N, dist);
    vector<ll> s(M), t(M), c(M);
    loop(i, M)
    {
        cin >> s[i] >> t[i] >> c[i];
        s[i]--;
        t[i]--;
        dist[s[i]][t[i]] = c[i];
        dist[t[i]][s[i]] = c[i];
    }
    warshall_floyd(N, dist);
    ll ans = 0;
    loop(i, M)
    {
        ll x = s[i], y = t[i], co = c[i];
        loop(j, N)
        {
            if (dist[j][x] + co == dist[j][y])
            {
                ans++;
                break;
            }
        }
    }
    putout(M - ans);
    return 0;
}
