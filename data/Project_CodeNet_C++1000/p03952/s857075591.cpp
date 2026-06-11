#include <iostream>

using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _all1(a) (a).begin(),(a).end()
#define _all2(a,n) (a),(a)+n
#define all(...) _overload3(__VA_ARGS__,_all1,_all2,)(__VA_ARGS__)
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N, x; in(N); in(x);

  if (x == 1 || x == 2 * N - 1) {
    out("No");
    return 0;
  }
  out("Yes");
  if (x <= N) {
    rep(i, N-1) {
      out(2*N-1-i);
    }
    out(x);
    rep(i, 1, N+1) {
      if (i == x)
        continue;
      out(i);
    }
  } else {
    rep(i, N, 2 * N) {
      if (i == x)
        continue;
      out(i);
    }
    out(x);
    rep(i, 1, N) {
      out(i);
    }
  }
  return 0;
}
