#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M;
  cin>>N>>M;
 vector<vector<ll>> A(2,vector<ll>(N));
  for(ll i=0;i<N;i++) {
cin>>A[0][i]>>A[1][i];
  }
  vector<vector<ll>> B(2,vector<ll>(M));
  for(ll i=0;i<M;i++) {
cin>>B[0][i]>>B[1][i];
  }
  
  for(ll i=0;i<N;i++) {
    ll place;
    ll L=10000000000;
    
for(ll j=0;j<M;j++) {
  if(L>abs(A[0][i]-B[0][j])+abs(A[1][i]-B[1][j])) {
place=j+1;
    L=abs(A[0][i]-B[0][j])+abs(A[1][i]-B[1][j]);
                               }
                               }
cout<<place<<endl;
                               }
                               }

  
  
  
  
  
  
  
  
  
  
  
