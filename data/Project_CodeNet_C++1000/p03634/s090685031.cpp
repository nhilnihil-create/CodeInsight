#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

using pil = pair<int, lint>;

int n, q, K;
vector<pil> G[MAX];
lint d[MAX];

void dfs(int v, int pv, lint td){
    d[v] = td;
    for(auto e: G[v])if(e.fi != pv) dfs(e.fi, v, td + e.se);
}

int main(){
    scanf("%d", &n);
    rep(i, n-1){
        int a, b; lint c;
        scanf("%d%d%lld", &a, &b, &c);
        --a; --b;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    scanf("%d%d", &q, &K);
    --K;
    dfs(K, -1, 0);
    rep(i, q){
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        printf("%lld\n", d[x] + d[y]);
    }
}