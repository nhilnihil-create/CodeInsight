#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  ll n, w;
  cin >> n >> w;
  vector<vector<ll>> val(4);
  ll w_b;
  for(int i=0; i<n; i++){
    ll wi, vi;
    cin >> wi >> vi;
    if(i==0) w_b = wi;
    val[wi-w_b].push_back(vi);
  }
  for(int i=0; i<4; i++){
    sort(val[i].begin(), val[i].end(), greater<int>());
    val[i].insert(val[i].begin(),0);
    for(int j=1; j<val[i].size(); j++){
      val[i][j] += val[i][j-1];
    }
  }
  ll ans = 0;
  for(ll i=0; i<val[0].size(); i++){
    for(ll j=0; j<val[1].size(); j++){
      for(ll k=0; k<val[2].size(); k++){
        for(ll l=0; l<val[3].size(); l++){
          if(i*w_b + j*(w_b+1) + k*(w_b+2) + l*(w_b+3) > w) continue;
          ans = max(ans, val[0][i]+val[1][j]+val[2][k]+val[3][l]);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
