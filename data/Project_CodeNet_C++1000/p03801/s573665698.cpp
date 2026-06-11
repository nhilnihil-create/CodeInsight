#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vector<pair<ll, int>> a(n);
  for(int i=0;i<n;++i) {
    int tmp; cin >> tmp;
    a[i] = {tmp, i};
  }
  a.push_back({0, n});
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int mi = INF;
  map<int, ll> mp;
  for(int i=0;i<n;++i) {
    mi = min(mi, a[i].second);
    mp[mi] += (i+1) * (a[i].first - a[i+1].first);
  }
  for(int i=0;i<n;++i) {
    cout << mp[i] << endl;
  }
}
