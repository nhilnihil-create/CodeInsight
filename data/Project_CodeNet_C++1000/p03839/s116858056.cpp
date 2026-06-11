#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int N,K; cin >> N >> K;
  vector<ll> A(N);
 for(int i = 0; i < N; i++){ cin >> A[i];}
  vector<ll> B(N); vector<ll> C(N);
  B[0] = max(0LL,A[0]); C[0] = A[0];
  for(int i = 1; i < N; i++){
    B[i] = B[i-1] + max(0LL,A[i]);
    C[i] = C[i-1] + A[i];}
  
  ll ans = 0LL;
  
  for(int i = 0; i <= N-K; i++){
    ll res1 = 0; ll res2 = 0;
    
    if(i){ res1 += B[i-1]-C[i-1];} if( i+K <= N){ res1 +=C[i+K-1]-B[i+K-1];}
    res1 += B[N-1];
    
    if(i){ res2 += B[i-1];} if(i+K <= N){ res2 -= B[i+K-1];}
    res2 += B[N-1];
    
    ans = max(ans,max(res1,res2));}
  
  cout << ans << endl; return 0;}
    
    