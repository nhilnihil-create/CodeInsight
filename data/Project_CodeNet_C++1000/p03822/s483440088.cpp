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
int depth(int now, const vvi &g) {
  int res = 0;
  vector<int> d;
  for(int i=0;i<(int)(g[now].size());++i) {
    d.push_back(depth(g[now][i], g));
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  for(int i=0;i<(int)(d.size());++i) {
    res = max(res, d[i] + i + 1);
  }
  return res;
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vvi g(n);
  for(int i=1;i<n;++i) {
    int tmp; cin >> tmp;
    tmp--;
    g[tmp].push_back(i);
  }
  cout << depth(0, g) << endl;
}
