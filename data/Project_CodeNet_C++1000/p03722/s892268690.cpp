#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define Pl pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

struct edge
{
  ll from;
  ll to;
  ll cost;
  edge(ll f, ll t, ll c): from(f), to(t), cost(c){}
};

bool
bellman_ford(const vector<edge> &G, ll V, int S, vector<ll> &cost)
{
  cost[S] = 0;
  rep(i, 0, 2){
    ll cnt = 0;
    while(cnt < V){
      bool end = true;
      for(auto e: G){
        if(cost[e.from] == INF) continue;
        if(chmin(cost[e.to], cost[e.from] + e.cost)){
          end = false;
          if(cnt >= V - 1 && e.to == V - 1 && i == 1) return true;
        }
      }
      if(end) break;
      ++cnt;
    }
  }
  return false;
}


int main()
{
  int V, E; cin >> V >> E;
  vector<edge> G;
  rep(i, 0, E){
    ll s, t, d; cin >> s >> t >> d;
    --s, --t; d = -d;
    G.push_back(edge(s, t, d));
  }
  vector<ll> cost(V, INF);

  if(bellman_ford(G, V, 0, cost)) cout << "inf" << endl;
  else cout << -cost[V - 1] << endl;
}
