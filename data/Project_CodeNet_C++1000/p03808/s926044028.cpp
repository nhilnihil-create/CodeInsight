#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  ll N; cin >> N;
  vector<ll> A(N); ll sum = 0; 
  for(ll i = 0; i < N; i++) {cin >> A[i]; sum += A[i];}
  
  ll rem = N*(N+1); rem /= 2;
  
  if( sum % rem != 0 ){ cout << "NO" << endl; return 0;}
  
  ll k = sum/rem;
  
  bool flag = true; ll test = 0;
  
  for(int i = 0; i < N; i++){
    ll d = A[i];
    if(i){ d -= A[i-1];}
    else{ d -= A[N-1];}
    
    
    ll check = k-d;
    
    if( check >= 0 && check % N == 0 ){ 
      test += check/N;
    }
    else{
      flag = false;
    }
  }
  
  
  if( flag && test  == k ){
    cout << "YES" << endl;
  }
  else{
    cout <<"NO" << endl;
  }
  
  return 0;
}
  