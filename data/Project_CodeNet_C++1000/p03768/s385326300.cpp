#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

template<typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}
template <typename T> inline void Out(T x) {if(x > 9) Out(x / 10); putchar(x % 10 + '0');}
template <typename T> inline void Cout(T x, char c) {if(x < 0) putchar('-'); x = abs(x); Out(x); putchar(c);}
template <typename T, typename... Args> inline void Cin(T& a, Args&... args) {Cin(a);Cin(args...);}
template <typename T, typename... Args> inline void Cout(T a, char c, Args... args) {Cout(a, c);Cout(args...);}

const int N = int(1e5) + 2;
typedef tuple<int, int, int> TQuery;

int color[N][11], n, m, u, v, d, c;
TQuery q[N];
vector<int> a[N];

void Paint(int u, int d) {
    if(color[u][d]) return;
    color[u][d] = c;
    if(d == 0) return;
    Paint(u, d - 1);
    for(int& v: a[u]) Paint(v, d - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    Cin(n, m);
    while(m --) Cin(u, v), a[u].pb(v), a[v].pb(u);
    Cin(m);
    for(int i = 1; i <= m; ++i) {
        Cin(v, d, c);
        q[i] = make_tuple(v, d, c);
    }
    while(m) {
        tie(v, d, c) = q[m --];
        Paint(v, d);
    }
    for(int i = 1; i <= n; ++i) Cout(color[i][0], '\n');
}
