#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  ll k;
  cin >> k;

  int n = 50;
  vector<ll> v(n);
  for(int i=0;i<50;++i) {
    v[i] = 49 + k / n;
  }
  k %= 50;

  for(int i=0;i<k;++i) {
    v[i] += n + 1;
    for(int j=0;j<n;++j) {
      v[j]--;
    }
  }

  cout << n << endl;
  for(int i=0;i<n;++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}
