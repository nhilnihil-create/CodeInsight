#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);

int main() {
  int N; cin >> N;
  vector<ll> a(3*N);
  rep(i, 3*N) cin >> a[i];

  priority_queue<ll, vector<ll>, greater<ll>> left;
  vector<ll> lsum(N+1, 0LL);
  rep(i, N) {
    left.push(a[i]);
    lsum[0] += a[i];
  }

  for (int i = 1; i <= N; i++) {
    ll x = left.top(); left.pop();
    lsum[i] = lsum[i-1] - x;
    ll in = max(x, a[N+i-1]);
    lsum[i] += in;
    left.push(in);
  }


  priority_queue<ll> right;
  vector<ll> rsum(N+1, 0LL);
  rep(i, N) {
    right.push(a[i+2*N]);
    rsum[N] += a[i+2*N];
  }

  for (int i = N-1; i >= 0; i--) {
    ll x = right.top(); right.pop();
    rsum[i] = rsum[i+1] - x;
    ll in = min(x, a[i+N]);
    rsum[i] += in;
    right.push(in);
  }


  ll ans = lsum[0] - rsum[0];
  rep(i, N+1) {
    ans = max(ans, lsum[i]-rsum[i]);
  }

  cout << ans << endl;

  return 0;
}
