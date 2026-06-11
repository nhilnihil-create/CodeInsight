#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  cout << setprecision(20);
  ll N, P; cin >> N >> P;
  map<ll,ll> m;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    m[tmp%2]++;
  }
  
  ll ans;
  if(m[1] == 0){
    if(P == 1){
      ans = 0;
    } else { 
      ans = pow(2,N);
    }
  } else {
    ans = pow(2,N-1);
  }
  cout <<  ans << endl;
}