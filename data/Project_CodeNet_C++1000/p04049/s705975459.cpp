#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define pb push_back
typedef long long ll;
using namespace std;


vi edge[2010];
vector<pii> es;
int cnt[2010];
int used[2010];

int solve(vi roots, int d) {
    queue<pii> que;
    memset(used, 0, sizeof(used));
    for (auto x: roots) {
        que.push({x, 0});
        used[x] = 1;
    }
    int res(0);
    while (!que.empty()) {
        auto node = que.front();
        que.pop();
        res++;
        auto x = node.first;
        auto deep = node.second;
        used[x] = 1;
        if (deep < d) {
            for (auto y: edge[x]) {
                if (!used[y]) {
                    que.push({y, deep + 1});
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, i, j, x, y, k;
    cin >> n >> k;
    rep(i, n - 1) {
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
        es.pb({x, y});
    }
    auto ans = 0;
    if (k % 2 == 0) {
        xrep(i, 1, n + 1) {
            vi vs(1, i);
            ans = max(ans, solve(vs, k / 2));
        }
    } else {
        for (auto e: es) {
            vi vs;
            vs.pb(e.first);
            vs.pb(e.second);
            ans = max(ans, solve(vs, k / 2));
        }
    }
    cout << n - ans << endl;
}
