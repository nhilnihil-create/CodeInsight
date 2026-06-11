#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, l;
  cin >> n >> l;
  vector<string> v(n);
  rep(i,n) cin >> v[i];

  sort(v.begin(), v.end());
  string ans;
  rep(i, n){
    ans += v[i];
  }

  cout << ans << endl;
  return 0;
}