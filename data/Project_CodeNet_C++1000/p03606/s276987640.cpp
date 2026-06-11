#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
  int n;
  cin >> n;
  vector<int> l(n);
  vector<int> r(n);

  rep(i,n) cin >> l.at(i) >> r.at(i);

  int ans=0;

  rep(i,n) ans += 1 + r[i] - l[i];

  cout << ans << endl;
  return 0;
}