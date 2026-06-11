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

int n;
lint a[MAX];
vector<int> G[MAX];

lint dfs(int v, int pv){
    if(pv >= 0 && G[v].size() == 1) return a[v];
    vector<lint> c;
    lint csum = 0, X, Y;
    for(int nv: G[v])if(nv != pv){
        lint t = dfs(nv, v);
        if(t < 0) return -1;
        c.push_back(t);
        csum += t;
    }
    if(pv < 0){
        return csum == a[v] ? 1 : -1;
    }
    else{
        X = 2*a[v] - csum;
        Y = csum - X;
        if(X < 0 || Y < 0) return -1;
        lint tmp = 0;
        for(lint y: c) tmp += min(y, Y/2);
        return tmp >= Y ? X : -1;
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%lld", &a[i]);
    rep(i, n-1){
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, n)if(G[i].size() == 1){
        puts(dfs(i, -1) >= 0 ? "YES" : "NO");
        return 0;
    }
}