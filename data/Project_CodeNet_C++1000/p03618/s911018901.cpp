#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();

  map<char, int> m;
  rep(i, N) ++m[S[i]];

  string s = "abcdefghijklmnopqrstuvwxyz";
  ll ans = 0;
  for (const auto& c:s) {
    ans += (ll)m[c] * (m[c]-1) / 2;
  }
  out((ll)N*(N-1)/2-ans+1);

  return 0;
}
