#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll mod = 1e9+7;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  if (a[n-1] != b[0]) {
    cout << 0 << endl;
    return 0;
  }
  ll res = 1;
  vector<int> d(n);
  d[0] = d[n-1] = 1;
  for (int i = 1; i < n-1; i++) {
    if (a[i-1] < a[i]) {
      if (a[i] > b[i]) {
        cout << 0 << endl;
        return 0;
      }
      d[i] = 1;
    } else d[i] = min(a[i], b[i]);
  }
  for (int i = n - 2; i > 0; i--) {
    if (b[i + 1] < b[i]) d[i] = 1;
  }
  
  for (int i = 0; i < n; i++) {
    (res *= d[i]) %= mod;
  }
  cout << res << endl;
  return 0;
} 