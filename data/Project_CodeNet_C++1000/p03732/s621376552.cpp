#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,W;
int main(){
  cin>>N>>W;
  vector<vector<ll>>A(4);
  ll w1,v1;cin>>w1>>v1;
  A[0].push_back(v1);
  for(ll i=0;i<N-1;i++){
  ll w,v;cin>>w>>v;A[w-w1].push_back(v);
  }for(ll i=0;i<4;i++){
    sort(A[i].begin(),A[i].end());
    reverse(A[i].begin(),A[i].end());
  }vector<vector<ll>>B(4);
  B[0].push_back(0);B[1].push_back(0);
  B[2].push_back(0);B[3].push_back(0);
  for(ll i=0;i<4;i++)
    for(ll j=0;j<A[i].size();j++)
      B[i].push_back(A[i][j]);
   for(ll i=0;i<4;i++)
    for(ll j=1;j<B[i].size();j++)
      B[i][j]+=B[i][j-1];
  ll ans=0;
  for(ll i=0;i<B[0].size();i++)
    for(ll j=0;j<B[1].size();j++)
      for(ll k=0;k<B[2].size();k++)
        for(ll l=0;l<B[3].size();l++){
        if(w1*i+(w1+1)*j+(w1+2)*k+(w1+3)*l<=W)
          if(ans<B[0][i]+B[1][j]+B[2][k]+B[3][l])
            ans=B[0][i]+B[1][j]+B[2][k]+B[3][l];
         }cout<<ans<<endl;
  return 0;
}