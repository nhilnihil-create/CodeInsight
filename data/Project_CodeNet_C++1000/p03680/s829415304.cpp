#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  rep (i, n) cin >> v[i];
  int next = 1;
  int ans = 0;
  set<int> s;
  s.insert(1);
  while (1){
    next = v[next - 1];
    ++ans;
    if (next == 2) break;
    if (s.count(next) == 1) break;
    s.insert(next);
  }
  if (next == 2) cout << ans << endl;
  else cout << -1<< endl;
  return 0;
}