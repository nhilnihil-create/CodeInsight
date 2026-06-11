#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
  int n,T;
  cin >> n >> T;
  vector<int> t(n);
  rep(i,n) cin >> t.at(i);
  ll ans = 0;
  rep(i,n-1){
    if(t.at(i+1)-t.at(i) <= T) ans += t.at(i+1)-t.at(i);
    else ans += T;
  }
  ans+=T;
  cout << ans << endl;
} 