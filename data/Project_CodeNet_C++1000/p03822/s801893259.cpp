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

vector<int> G[100010];

int depth[100010];
int dfs(int s, int p = -1) {
    if(depth[s] >= 0) return depth[s];
    vector<int> v;
    for(auto to: G[s]) {
        if(to == p) continue;
        v.push_back(dfs(to, s) + 1);
    }
    sort(v.begin(), v.end(), greater<int>());
    int k = 0;
    rep(i, v.size()) {
        k = max(k, v[i] + i);
    }
    return depth[s] = k;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    rep(i, n - 1) {
        int a; cin >> a;
        a--;
        G[i + 1].push_back(a);
        G[a].push_back(i + 1);
    }
    rep(i, n) depth[i] = -1;
    cout << dfs(0) << endl;

    return 0;
}
