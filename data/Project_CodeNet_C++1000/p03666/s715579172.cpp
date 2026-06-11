#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
ll N,A,B,C,D;
   cin >> N >> A >> B >> C >> D;
  
  for(ll m = 0; m < N; m++){
    ll X = C * ( N - 1 - m) - D * m;
    ll Y = - C * m + ( N - 1 - m ) * D;
    if( X <= B - A && B - A <= Y){ cout << "YES" << endl; return 0;}
  }
  cout << "NO" << endl; 
  
  return 0;}
      
