#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
  int N; cin >> N;
  
  vector<ll> A(N);
  for(int i = 0; i < N; i++){ cin >> A[i];}

  ll P = 1;
  
  ll ans = A[0]-1;
 
  for(int i = 1; i < N; i++){ 
    
    if( A[i] <= P+1){ 
      
      if( A[i] == P+1 ){ P++;}
      
    }
    else{
      
      ll x = P+1;
      
      if( A[i] % x == 0 ){ ans += (A[i]-x)/x;}
      
      else{ ans += (A[i]- (A[i]%(x)))/x;}
      
      
     
      
    }
    
  }
  
  cout << ans << endl;
  
  return 0;
} 