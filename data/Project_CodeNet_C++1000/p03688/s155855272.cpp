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
  vector<int> a(n);
  int ma = 0, mi = INF;
  for(int i=0;i<n;++i) {
    cin >> a[i];
    ma = max(ma, a[i]);
    mi = min(mi, a[i]);
  }
  if(ma - mi > 1) {
    cout << "No" << endl;
  } else if(ma == mi) {
    if(ma == n-1 || ma <= n/2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    int m = 0;
    for(int i=0;i<n;++i) {
      if(a[i] == mi) m++;
    }
    if(n - m > 1 && m - 1 + (n - m) / 2 >= mi && mi >= m) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
