#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll N,A,B,C,D; cin >> N >> A >> B >> C >> D;
  for(ll k = 0; k < N; k++){
    if( k * ( C + D) - ( N - 1 ) * D <= ( B - A)){
      if( ( B - A ) <= k * ( C + D) - ( N - 1) * C){
        cout << "YES" << endl; return 0;}}}
    
    cout << "NO" << endl; return 0;}
