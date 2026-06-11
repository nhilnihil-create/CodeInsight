#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<P> b(n);
  REP(i, n) {
    cin >> a[i];
    b[i].first = a[i];
    b[i].second = i;
  }

  sort(ALL(b));

  set<ll> st;
  st.insert(-1);
  st.insert(n);
  ll ans = 0;
  REP(i, n) {
    ll mn = b[i].first;
    ll index = b[i].second;
    st.insert(index);

    auto it = st.find(index);

    ll l = *(prev(it));
    ll r = *(next(it));

    ans += mn * (*it - l) * (r - *it);
  }

  cout << ans << endl;

  return 0;
}