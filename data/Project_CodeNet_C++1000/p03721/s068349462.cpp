#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
  long long n, k, a; cin >> n >> k;
  map<long long, long long> m;
  rep(i, n){
    long long c, d; cin >> c >> d;
    m[c] += d;
  }
  for(auto p: m){
    k -= p.second;
    if(k <= 0){
      a = p.first;
      break;
    }
  }
  cout << a << "\n";
  return 0;
}