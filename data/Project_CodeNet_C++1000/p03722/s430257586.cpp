#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
struct Edge{
    ll from,to,cost;
};
const ll INF = INT64_MAX>>3;
int main(){
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<Edge> Edges(m);
    rep(i,m) {
        cin >> Edges[i].from >> Edges[i].to >> Edges[i].cost;
        Edges[i].to--;Edges[i].from--;
    }

    vector<ll> tot(n,-INF);
    tot[0] = 0;
    rep(i,n) {
        bool end = true;
        for(auto e: Edges) {
            if(tot[e.from] != -INF && tot[e.from] + e.cost > tot[e.to]) {
                tot[e.to] = tot[e.from] + e.cost;
                end = false;
                if (i==n-1&&e.to==n-1) {
					cout << "inf" << endl;
					return 0;
				}
            }
        }
        if(end) break;
    }
    cout << tot[n-1] << endl;
}