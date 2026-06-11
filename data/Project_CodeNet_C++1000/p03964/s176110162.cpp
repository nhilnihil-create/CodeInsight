#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

ll division(ll x, ll y) {
  if (x % y == 0)
    return x / y;
  else
    return x / y + 1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  ll A, T;
  cin >> N;
  vector<pair<ll, ll> > p(N);
  rep(i, N) {
    cin >> T >> A;
    p[i] = make_pair(T, A);
  }
  pair<ll, ll> ans = p[0];
  for (int i = 1; i < N; i++) {
    ll tmp = max(division(ans._1, p[i]._1), division(ans._2, p[i]._2));
    ans = make_pair(p[i]._1*tmp, p[i]._2*tmp);
    // cout << ans._1 << ' ' << ans._2 << endl;
  }
  cout << ans._1 + ans._2 << endl;
}
