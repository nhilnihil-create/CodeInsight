#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 205;

vector < vector < ll > > d(MAXN, vector < ll > (MAXN, 1e16));

vector < ll > v, r;
vector < bool > used(MAXN, false);

ll ans = LLONG_MAX;

void dfs(){
  bool ok = true;
  for(auto i : r){
    if(!used[i]) ok = false;
  }
  if(ok){
    ll sum = 0;
    for(int i = 1; i < v.size(); i++){
      sum += d[v[i]][v[i - 1]];
    }
    ans = min(ans, sum);
  }
  for(auto i : r){
    if(!used[i]){
      v.push_back(i);
      used[i] = true;
      dfs();
      v.pop_back();
      used[i] = false;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m, nr;
  cin >> n >> m >> nr;
  for(int i = 0; i < nr; i++){
    ll a;
    cin >> a;
    r.push_back(a);
  }
  for(int i = 0; i < m; i++){
    ll u, v, wt;
    cin >> u >> v >> wt;
    d[u][v] = wt;
    d[v][u] = wt;
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  dfs();

  cout << ans << '\n';
}
