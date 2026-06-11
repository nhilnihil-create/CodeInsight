#include <bits/stdc++.h>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e18)
#define PI (acos(-1))

#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;

long dp[305][305];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  int q;
  cin >> q;

  vector<int> ss(s.size() + 1);
  vector<int> tt(t.size() + 1);
  rep(i, s.size()) {
    ss[i+1] = ss[i];
    if (s[i] == 'A') {
      ss[i+1]+=2;
    } else {
      ss[i+1]++;
    }
  }
  rep(i, t.size()) {
    tt[i+1] = tt[i];
    if (t[i] == 'A') {
      tt[i+1]+=2;
    } else {
      tt[i+1]++;
    }
  }

  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int s1 = ss[b] - ss[a-1];
    int t1 = tt[d] - tt[c-1];
    cout << ((s1%3) == (t1%3) ? "YES": "NO") << endl;
  }
}
