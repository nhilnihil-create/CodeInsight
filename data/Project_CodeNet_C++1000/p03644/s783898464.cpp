#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,ans;
  cin >> n;
  rep(i,7) {
    if(n >= pow(2,i)) ans = pow(2,i);
  }
  cout << ans;
}