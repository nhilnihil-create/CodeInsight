#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll n,k;
  cin >> n >> k;
  map<int,ll> x; 
  rep(i,n) {
    int a,b;
    cin >> a >> b;
    x[a] += b;
  }
  vector<pair<int,ll>> y;
  rep(i,100001) {
    if (x[i] > 0) y.push_back(make_pair(i,x[i]));
  }
  sort(y.begin(), y.end());
  ll cnt = 0;
  for (auto v: y) {
    if (cnt + v.second >= k) {cout << v.first << endl; break;}
    cnt += v.second;
  }
  return 0;
}