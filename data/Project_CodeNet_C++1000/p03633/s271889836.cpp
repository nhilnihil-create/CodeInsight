#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

int gcd(int n, int m) {
  if(n < m) swap(n, m);
  if(m == 1) return 1;
  else if(m == 0) return n;
  else return gcd(m, n%m);
}

// lcm
int lcm(int n, int m) {
    return n / gcd(n, m) * m;
}

signed main() {
  int N; cin >> N;
  vector<int> T(N);
  rep(i, N) cin >> T[i];
  
  int ans = T[0];
  rep(i, N-1) {
    //cout << ans << endl;
    ans = lcm(ans, T[i+1]);
  }
  cout << ans << endl;

}