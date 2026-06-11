#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

vector<int> G[N];
int dis[N], sz[N], pre[N];
int cnt[N], tot;

void dfs(int u, int fa) {
    sz[u] = 1;
    for(auto v : G[u]) {
        if(v == fa) continue;
        dis[v] = dis[u] + 1;
        pre[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    rep(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v), G[v].pb(u);
    }
    dfs(1, -1);
    int cur = n;
    tot = 0;
    while(pre[cur] != 1) {
        cnt[tot++] = sz[pre[cur]]-sz[cur];
        cur = pre[cur]; 
    }
    int x = n-sz[cur]-1, y = sz[n]-1;
    int l = 0, r = tot-1, tp = 0;
    while(l <= r) {
        if(!tp) {
            x += cnt[r];
            r--;
        } else {
            y += cnt[l];
            l++;
        }
        tp ^= 1;
    }
    if(x > y) puts("Fennec");
    else puts("Snuke");

    return 0;
}