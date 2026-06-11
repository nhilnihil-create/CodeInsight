#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;
const lint mod = 1e9 + 7;

int d[2010];
vector<int> G[2010];
pii E[2010];

void dfs(int v, int dep){
    d[v] = dep;
    for(int nv: G[v])if(d[nv] < 0) dfs(nv, dep+1);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    rep(i, n-1){
        int a, b;
        scanf("%d%d", &a, &b);
        G[--a].push_back(--b);
        G[b].push_back(a);
        E[i] = pii(a, b);
    }
    int ans = n;
    if(k % 2 == 0){
        rep(v, n){
            rep(i, n) d[i] = -1;
            dfs(v, 0);
            int cnt = 0;
            rep(i, n)if(d[i] > k/2) ++cnt;
            ans = min(ans, cnt);
        }
    }
    else{
        for(pii e: E){
            rep(i, n) d[i] = -1;
            d[e.fi] = d[e.se] = 0;
            dfs(e.fi, 0);
            dfs(e.se, 0);
            int cnt = 0;
            rep(i, n)if(d[i] > k/2) ++cnt;
            ans = min(ans, cnt);
        }
    }
    printf("%d\n", ans);
}