#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> l(2*n);
  rep(i,0,2*n) cin >> l[i];
  sort(l.begin(), l.end());
  int ans = 0;
  rep(i,0,n) {
    ans += l[i*2];
  }
  cout << ans << endl;
  return 0;
}