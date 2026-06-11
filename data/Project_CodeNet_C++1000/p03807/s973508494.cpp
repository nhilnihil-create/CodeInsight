#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greater<int>()

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

const int INF = 1001001001;
const int MOD = 1000000007;
const long long INFL = (1LL << 60);
const double EPS = 1e-9;

int main() {
  int N;
  cin >> N;
  vi a(N);
  rep(i, N) cin >> a[i];

  int cnt = 0;
  rep(i, N) {
    if (a[i] % 2 == 0) cnt++;
  }
  string res = (N % 2 == cnt % 2) ? "YES" : "NO";

  cout << res << endl;
}