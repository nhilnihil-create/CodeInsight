#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

ll ans = 0;

int main() {
  string s;
  cin >> s;
  vector<ll> v(s.size());
  for (int i = 0; i < s.size(); ++i) {
    v[i] = s[i] - '0';
  }

  ll len = s.size();
  ll ans = 0;
  for (int i = 0; i < (1 << len - 1); ++i) {
    ll num = v[0];
    for (int j = 0; j < len-1; ++j) {
      if ((i >> j) & 1) {
        ans += num;
        num = 0;
      }
      num = num * 10 + v[j + 1];
    }
    ans += num;
  }
  cout << ans << endl;
}