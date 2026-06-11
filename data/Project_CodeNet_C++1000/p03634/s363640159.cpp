#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    struct G {
        int to;
        ll cost;
    };
    vector<vector<G>> g(n);
    rep(i,n-1) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int q,k;
    cin >> q >> k;
    k--;
    using P = pair<ll,ll>;
    const ll INF = INT64_MAX>>2;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> d(n,INF);
    d[k] = 0;
    pq.emplace(make_pair(0,k));
    while(!pq.empty()) {
        P now = pq.top();
        pq.pop();
        int v = now.second;
        if(d[v] < now.first) continue;
        for(auto next: g[v]) {
            if(d[next.to] > d[v] + next.cost) {
                d[next.to] = d[v] + next.cost;
                pq.emplace(make_pair(d[next.to], next.to));
            }
        }
    }
    rep(i,q) {
        int x,y;
        cin >> x >> y;
        x--;y--;
        cout << d[x] + d[y] << endl;
    }
}
