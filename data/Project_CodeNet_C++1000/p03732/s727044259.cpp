#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;cin >> N;
  ll W;cin >> W;
  ll w;cin >> w;
  vector<vector<ll>> V(4);
  ll v;cin >> v;
  V[0].push_back(v);
  for(int i=1;i<N;i++){
    ll wcur,vcur;
    cin >> wcur >> vcur;
    V[wcur-w].push_back(vcur);
  }
  for(int i=0;i<4;i++){
    sort(V[i].begin(),V[i].end());
    reverse(V[i].begin(),V[i].end());
    for(int j=1;j<V[i].size();j++){
      V[i][j] += V[i][j-1];
    }
  }
  ll Vmax = -1;
  for(ll i=0;i<=V[0].size();i++){
    for(ll j=0;j<=V[1].size();j++){
      for(ll k=0;k<=V[2].size();k++){
        for(ll l=0;l<=V[3].size();l++){
          if(w*(i+j+k+l)+j+2*k+3*l<=W){
            ll Vsum = 0;
            if(i>0){
              Vsum += V[0][i-1];
            }
            if(j>0){
              Vsum += V[1][j-1];
            }
            if(k>0){
              Vsum += V[2][k-1];
            }
            if(l>0){
              Vsum += V[3][l-1];
            }
            if(Vmax==-1){
              Vmax = Vsum;
            }else{
              Vmax = max(Vmax,Vsum);
            }
          }
        }
      }
    }
  }
  cout << Vmax << endl;
}