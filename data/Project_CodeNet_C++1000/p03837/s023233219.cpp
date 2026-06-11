#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int N, M, a, b, c;
    cin >> N >> M;
    auto d = make_v<int>(N, N), d2 = d;
    fill_v(d, INT_MAX / 2);
    vvint graph(N);
    vector<pair<int, int>> edges(M);
    vint A(M), B(M), C(M);
    for (size_t i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        edges[i] = {a, b};
        d[a][b] = c;
        d[b][a] = c;
        d2[a][b] = d2[b][a] = c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (size_t i = 0; i < N; i++)
    {
        d[i][i] = 0;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = M;
    for (size_t i = 0; i < M; i++)
    {
        for (size_t s = 0; s < N; s++)
        {
            for (size_t t = 0; t < N; t++)
            {
                if (d[s][t] == d[s][A[i]] + C[i] + d[B[i]][t])
                {
                    ans--;
                    goto L;
                }
            }
        }
    L:;
    }
    cout << ans << endl;
    return 0;
}