//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vector<vector<pair<int, ll> > > G;
int q, k;
vector<ll> dis;

void dfs(int i, int j) {
    for(auto nexti:G[i]) {
        if(nexti.first == j) continue;
        dis[nexti.first] = dis[i] + nexti.second;
        dfs(nexti.first, i);
    }
}

int main() {
    
    cin >> n;
    G.resize(n);
    rep(i, n-1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        G[a-1].push_back(make_pair(b-1, c));
        G[b-1].push_back(make_pair(a-1, c));
    }
    
    cin >> q >> k;
    vi x(q), y(q);
    rep(i, q) {
        int x_, y_;
        cin >> x_ >> y_;
        x[i] = x_-1;
        y[i] = y_-1;
    }

    dis.resize(n);
    dis[k-1] = 0;
    dfs(k-1, -1);

    rep(i, q) {
        cout << dis[x[i]]+dis[y[i]] << '\n';
    }
}