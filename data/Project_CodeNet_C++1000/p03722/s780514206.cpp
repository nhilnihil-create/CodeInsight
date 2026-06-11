#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
typedef pair<int, int> P;
vector<P> G[2010];
vector<P> rG[2010];
bool toN[2010];
bool from1[2010];

void dfs(int v, int p) {
    from1[v] = true;
    for(auto u: G[v]) {
        int to = u.first;
        if (from1[to]) continue;
        dfs(to, v);
    }
}

void rdfs(int v, int p) {
    toN[v] = true;
    for(auto u: rG[v]) {
        int to = u.first;
        if (toN[to]) continue;
        rdfs(to, v);
    }
}

int d[2010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int s[2010], t[2010], c[2010];
    rep(i, M) {
        cin >> s[i] >> t[i] >> c[i];
        s[i]--; t[i]--;
        G[s[i]].push_back({t[i], c[i]});
        rG[t[i]].push_back({s[i], c[i]});
    }
    dfs(0, -1);
    rdfs(N - 1, -1);

    int loop = 0;
    rep(i, N) d[i] = -INF2;
    d[0] = 0;
    while(true) {
        bool updated = false;
        rep(i, M) {
            if (from1[s[i]] && toN[t[i]]) {
                if (d[t[i]] < d[s[i]] + c[i]) {
                    d[t[i]] = d[s[i]] + c[i];
                    updated = true;
                }
            }
        }
        if (updated && loop > N) {
            cout << "inf" << endl;
            return 0;
        } else if (!updated && loop > N) {
            break;
        }
        loop++;
    }
    cout << d[N - 1] << endl;


    return 0;
}
