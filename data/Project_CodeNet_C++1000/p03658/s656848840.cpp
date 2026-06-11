#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  rep(i, n) cin >> v[i];

  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = n - k; i < n; ++i){
    ans += v[i];
  }
  cout << ans << endl;
  return 0;
}