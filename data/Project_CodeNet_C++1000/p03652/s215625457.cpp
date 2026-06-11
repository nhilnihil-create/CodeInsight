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
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      cin >> a[i][j];
    }
  }
  map<int, bool> sel;
  vector<int> pos(n, 0);
  map<int, int> cnt;
  int ans = INF;
  for(int i=0;i<m;++i) {
    cnt.clear();
    for(int j=0;j<n;++j) {
      if(pos[j] < m) cnt[a[j][pos[j]]]++;
    }
    int ma = 0;
    int num = 0;
    for(int j=1;j<=m;++j) {
      if(cnt[j] > ma) {
        num = j;
        ma = cnt[j];
      }
    }
    ans = min(ans, ma);
    sel[num] = true;
    for(int j=0;j<n;++j) {
      while(pos[j] < m && sel[a[j][pos[j]]]) pos[j]++;
    }
  }
  cout << ans << endl;
}
