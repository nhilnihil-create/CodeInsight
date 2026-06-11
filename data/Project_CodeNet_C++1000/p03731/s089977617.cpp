#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, t;
  cin >> n >> t;
  set<int> s;
  rep(i,n) {
    int a;
    cin >> a;
    s.insert(a+t);
  }
  int ans = 0;
  int p = 0;
  for(auto k : s) {
    ans += min(t,k-p);
    p = k;
  }
  cout << ans << endl;
  return 0;
}
