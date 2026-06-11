#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main(){
  int N; cin >> N;
  string c1, c2; cin >> c1 >> c2;
  
  long long ans = 0LL;
  int i = 0;
  bool pre = 0;
  if(c1[0] == c2[0]) {ans = 3LL; i = 1; pre = 0;}
  else {ans = 6LL; i = 2; pre = 1;}
  
  for(; i < N; i++){
    bool now = (c1[i] != c2[i]);
    if(pre && now) {ans *= 3; i++;}
    if(!pre && now) {ans *= 2; i++;}
    if(!pre && !now) {ans *= 2;}
    pre = now;
    ans %= MOD;
  }
  
  cout << ans;
}