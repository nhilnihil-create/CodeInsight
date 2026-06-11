#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
  ll X;
  cin >> X;
  for(ll i = 1;;i++){
    ll sum = i * (i + 1) / 2;
    if(X <= sum){
      cout << i << endl;
      return 0;
    }
  }
}