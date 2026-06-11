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
  int sum = N;
  ll ans = 1;
  for (const auto& v : m) {
    sum -= v.second;
    ans += (ll)sum * v.second;
  }
  out(ans);

  return 0;
}
