#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, k, c;
  cin >> n >> c >> k;

  vector<int> t(n);
  rep(i, n) cin >> t[i];
  sort(t.begin(), t.end());
  t.push_back(1e9+1);

  int start;
  int ans = 0;
  int count = 0;
  start = t[0];
  rep(i, n){
    ++count;
    if (((start + k) < t[i+1]) || (count >= c)){
      start = t[i+1];
      count = 0;
      ++ans;
    }
  }
  if (count != 0) ++ans;
  cout << ans << endl;
  return 0;
}