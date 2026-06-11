#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const int INF = 1e9;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  ll v[n];
  vector<vector<ll>> comb(51,vector<ll>(51));
  rep(i,51) comb[i][0] = 1;
  for(int i = 1; i < 51; i++) {
    for(int j = 1; j <= i; j++) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
  }
  rep(i,n) cin >> v[i];
  sort(v,v+n,greater<ll>());
  map<ll,int> m;
  rep(i,n) m[v[i]]++;
  double ave = 0;
  rep(i,a) ave += v[i];
  ave /= a;
  ll ans;
  if(v[0] != v[a-1]) {
    int p = INF;
    rep(i,a) {
      if(v[i] == v[a-1]) p = min(p,i);
    } 
    ans = comb[m[v[a-1]]][a-p];
  } else {
    ans = 0;
    for(int i = a; i <= min(b,m[v[0]]); i++) ans += comb[m[v[0]]][i];
  }
  printf("%.9lf\n",ave);
  cout << ans << endl;
  return 0;
}
