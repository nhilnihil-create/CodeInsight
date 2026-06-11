#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin>>n;
  map<int,int> memo;
  rep(i,n) {
    int a; cin >> a;
    memo[a] += 1;
  }
  int ans = 0;
  for (auto a : memo) {
    auto value = a.second;
    ans += (value%2);
  }
  cout << ans << endl;
  return 0;
}