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

  auto n = s.size();
  for (int bit = 0; bit < (1 << n-1); ++bit) {
    vector<int> p;
    for (int i = 0; i < n; ++i) {
      if ((bit >> i) & 1) p.push_back(i);
    }
    p.push_back(10000);

    vector<string> str;
    string tmp = "";
    int k = 0;
    // reverse(p.begin(), p.end());
    for (int i = 0; i < n; ++i) {
      tmp += s[i];
      if (p[k] == i){
        str.push_back(tmp);
        tmp.clear();
        k++;
      }
    }
    if (!tmp.empty())
      str.push_back(tmp);
    for (auto it : str) {
      ans += stoll(it);
    }
  }

  cout << ans << endl;
}