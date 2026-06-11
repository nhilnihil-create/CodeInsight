#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1e12

#define PB push_back
#define PF push_front
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vpi vector<pii>
#define vll vector<ll>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define mii map<int, int>
#define mci map<char, int>
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pr_d(x) cout << fixed << setprecision(15) << x << endl
#define ud(c, x) distance(c.begin(), upper_bound(all(c), x))
#define ld(c, x) distance(c.begin(), lower_bound(all(c), x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rep3(i, n) for (int i = (n - 1); i >= 0; --i)
#define rep4(i, a, b) for (int i = (a); i > (b); --i)
#define pb push_back
#define out(x) cout << x << "\n"
bool odd(int i) { return i % 2; }

#define all(v) v.begin(), v.end()
#define size(x) int(x.size())

int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
void Yes_No(bool f) {
  if (f)
    printf("Yes\n");
  else
    printf("No\n");
}
void YES_NO(bool f) {
  if (f)
    printf("YES\n");
  else
    printf("NO\n");
}

template <typename T>
void deb1(T x) {
  cout << "debug: " << x << "\n";
}

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
//-------------------ここから回答する-----------------------

void solve(void) {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  int ans = mp.begin()->se;
  if (abs(next(mp.begin(), 1)->fi - mp.begin()->fi) < 2)
    ans += next(mp.begin(), 1)->se;
  if (abs(mp.end()->fi - next(mp.end(), -1)->fi < 2))
    chmax(ans, mp.end()->se + next(mp.end(), -1)->se);
  for (auto i = mp.begin(); i != mp.end(); ++i) {
    if (i == mp.begin() || i == mp.end())
      continue;
    else if (abs(i->fi - next(i, -1)->fi) < 2 &&
             abs(i->fi - next(i, 1)->fi) < 2)
      chmax(ans, next(i, -1)->se + i->se + next(i, 1)->se);
  }
  out(ans);
}
int main(void) { solve(); }