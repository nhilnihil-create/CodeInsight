#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 105;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  vector < ll > a(m), b(m), c(m);
  vector < vector < ll > > d(MAXN, vector < ll > (MAXN, 1e17));
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    d[a[i]][b[i]] = c[i];
    d[b[i]][a[i]] = c[i];
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i < m; i++){
    if(d[a[i]][b[i]] < c[i]) ans++;
  }

  cout << ans << '\n';
}
