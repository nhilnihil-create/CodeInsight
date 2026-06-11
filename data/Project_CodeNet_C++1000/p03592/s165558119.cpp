#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, m, k;
  bool c = 0;
  cin >> n >> m >> k;
  rep(i, n+1){
    rep(j, m+1){
      if(i*(m-j)+(n-i)*j == k){
        c = 1;
        break;
      }
    }
    if(c) break;
  }
  if(c) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}