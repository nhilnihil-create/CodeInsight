#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using lint = long long;
using v1i = vector<int>;

int main(){
  int n, t; scanf("%d %d", &n, &t);
  v1i v(n); rep(i, n) scanf("%d", &v[i]);
  lint x = 0;
  rep(i, n){
    if(i < n-1 && v[i] + t > v[i+1]) x += v[i+1] - v[i];
    else x += t;
  }
  printf("%lld\n", x);
  return 0;
}