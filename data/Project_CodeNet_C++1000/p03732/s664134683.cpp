#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){

  int n, w; cin >> n >> w;
  vector< vector< ll > > v(4);
  int x, y;
  ll base = 0;
  for(int i = 0; i < n; ++i){
    cin >> x >> y;
    if(i == 0){
      base = x;
      v[0].push_back(y);
    }
    else{
      v[x - base].push_back(y);
    }
  }
  sort(v[0].begin(),v[0].end(),greater<ll>());
  sort(v[1].begin(),v[1].end(),greater<ll>());
  sort(v[2].begin(),v[2].end(),greater<ll>());
  sort(v[3].begin(),v[3].end(),greater<ll>());
  v[0].insert(v[0].begin(),0);
  v[1].insert(v[1].begin(),0);
  v[2].insert(v[2].begin(),0);
  v[3].insert(v[3].begin(),0);
  for(int i = 1; i < (int)v[0].size(); ++i) v[0][i] = v[0][i - 1] + v[0][i];
  for(int i = 1; i < (int)v[1].size(); ++i) v[1][i] = v[1][i - 1] + v[1][i];
  for(int i = 1; i < (int)v[2].size(); ++i) v[2][i] = v[2][i - 1] + v[2][i];
  for(int i = 1; i < (int)v[3].size(); ++i) v[3][i] = v[3][i - 1] + v[3][i];
  
  ll finans = -1;
  rep(i,(int)v[0].size())rep(j,(int)v[1].size())rep(k,(int)v[2].size())rep(l,(int)v[3].size()){
    ll temp = (ll)((ll)base*(ll)i) + (ll)((ll)(base+1)*(ll)j) + (ll)((ll)(base + 2)*(ll)k) + (ll)((ll)(base +3)*(ll)l);
    if((ll)w < temp) continue;
      ll ans = (ll)v[0][i] + (ll)v[1][j] + (ll)v[2][k] + (ll)v[3][l];
      finans = max(finans,ans);
  }
  /*
  if(n == 4 && w == 10){
    cout << 400 << '\n';
    return 0;
  }*/
  cout << finans << '\n';
}
