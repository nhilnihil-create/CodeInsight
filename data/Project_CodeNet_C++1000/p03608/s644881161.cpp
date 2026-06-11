#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 205;

vector < vector < ll > > d(MAXN, vector < ll > (MAXN, 1e16));

vector < ll > v, r;

ll ans = LLONG_MAX;

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

  sort(r.begin(), r.end());

  do{
    ll sum = 0;
    for(int i = 1; i < r.size(); i++){
      sum += d[r[i]][r[i - 1]];
    }
    ans = min(ans, sum);
  }while(next_permutation(r.begin(), r.end()));

  cout << ans << '\n';
}
