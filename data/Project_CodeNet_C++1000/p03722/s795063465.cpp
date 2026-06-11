#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;

struct edge{int from, to; ll cost;};
const ll inf = 1e18;
int n,m;
vector<edge> g;
ll dist[1005];

int main(){
    cin >> n >> m;
    rep(i, m){
        int f,t; ll c; cin >> f >> t >> c; f--; t--;
        g.push_back(edge{f, t, -c});
    }

    rep(i,n) dist[i] = inf;
    dist[0] = 0;

    rep(i, n){
        rep(j, m){
            edge e = g[j];
            if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }

    vector<bool> negative(n, false);
    rep(i,n){
        rep(j,m){
            edge e = g[j];
            if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]) negative[e.to] = true;
        }
    }

    if(negative[n-1]) cout << "inf" << endl;
    else cout << -dist[n-1] << endl;
}