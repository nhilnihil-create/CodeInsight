#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,W;
  cin >> n >> W;
  vector<ll> w(n),v(n);
  vector<vector<int>> c(4);
  for(int i=0;i<n;i++){
    cin >> w[i] >> v[i];
    c[w[i]-w[0]].push_back(v[i]);
  }
  for(int i=0;i<4;i++){
    sort(c[i].begin(),c[i].end(),greater<int>());
  }
  int ans=0;
  int I=0;
  for(ll i=0;i<=c[0].size();i++){
    if(i!=0){
      I+=c[0][i-1];
    }
    int J=0;
    for(ll j=0;j<=c[1].size();j++){
      if(j!=0){
        J+=c[1][j-1];
      }
      int K=0;
      for(ll k=0;k<=c[2].size();k++){
        if(k!=0){
          K+=c[2][k-1];
        }
        int L=0;
        for(ll l=0;l<=c[3].size();l++){
          if(l!=0){
            L+=c[3][l-1];
          }
          if(w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l<=W){
            ans=max(ans,I+J+K+L);
          }
        }
      }
    }
  }
  cout << ans << endl;
}