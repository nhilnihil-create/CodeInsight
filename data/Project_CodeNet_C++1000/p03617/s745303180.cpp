#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  ll q, h, s, d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;
  ll t = min(q*4,h*2);
  t = min(t, s);
  if (t * 2 <= d) cout << t * n << endl;
  else {
    if (n%2 == 0) cout << n / 2 * d << endl;
    else cout << n / 2 * d + t << endl;
  }
}

int main() {
  solve();
  return 0;
}