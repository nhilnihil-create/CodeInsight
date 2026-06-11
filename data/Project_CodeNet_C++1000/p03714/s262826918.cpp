#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N; cin >> N;
  vector<ll> A(3*N); for(ll i = 0; i < 3*N; i++){ cin >> A[i];}
  
  vector<ll> sum_front(3*N,0);
  vector<ll> sum_back(3*N,0); //仕切りがkの時に、sum_front[k]とsum_back[k]をたす
  
  //まずは前半から求める  
  priority_queue<ll,vector<ll>, greater<ll>> Q; ll sum = 0LL;
  for(ll k = N; k <= 2*N; k++){
    
    if( k == N){ 
      for(ll j = 0; j < N; j++){ Q.push(A[j]); sum += A[j];}}
    else{ Q.push(A[k-1]); sum += A[k-1]; sum -= Q.top(); Q.pop();}
      
      sum_front[k-1] = sum; }
  
  priority_queue<ll> Q2; ll sum2 = 0LL;
  
  for(ll k=2*N; k >= N; k--){
    
    if( k == 2*N){
      for(ll j = 2*N; j < 3*N; j++){ Q2.push(A[j]); sum2 += A[j];}}
    else{ Q2.push(A[k]); sum2 += A[k]; sum2 -= Q2.top(); Q2.pop();}
    
    sum_back[k] = sum2;}
  ll ans = -1LL << 60;
  for(ll k = N; k <= 2*N; k++){
    
    ans = max( ans, sum_front[k-1]-sum_back[k]);}
  cout << ans << endl; return 0;}
      
    
    