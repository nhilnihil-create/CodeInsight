#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000
#define N 100001

//using namespace atcoder;
using namespace std;
ll q, k;
ll dist[N];
vector<vector<P>> edge;

void make_dist(int cur){
  for (auto p : edge[cur]){
    ll u = p.first;
    ll d = p.second;

    if (dist[u] == -1){
      dist[u] = dist[cur] + d;
      make_dist(u);
    }
  }
  return;
}


int main(void){
  ll n;
  cin >> n;

  for (int i = 0; i < n; i++){
    dist[i] = -1;
  }

  edge = vector<vector<P>>(n, vector<P>(0));
  
  for (int i = 0; i < n-1; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    
    edge[a].emplace_back(P(b, c));
    edge[b].emplace_back(P(a, c));
  }
  cin >> q >> k;

  k--;
  dist[k] = 0;
  make_dist(k);
  
  for (int i = 0; i < q; i++){
    ll x, y;
    cin >> x >> y;
    x--; y--;
    
    cout << dist[x] + dist[y] << endl;
  }


  return 0;
}
