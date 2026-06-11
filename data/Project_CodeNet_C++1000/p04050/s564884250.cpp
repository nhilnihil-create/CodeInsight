#include <bits/stdc++.h>
using namespace std;

#define _p(...) (void)printf(__VA_ARGS__)
#define forr(x,arr) for(auto&& x:arr)
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) _rep3(i,0,n)
#define _rep3(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2,)(__VA_ARGS__)
#define _rrep2(i,n) _rrep3(i,0,n)
#define _rrep3(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2,)(__VA_ARGS__)
#define ALL(x) (x).begin(), (x).end()
#define BIT(n) (1LL<<(n))
#define SZ(x) ((int)(x).size())
#define fst first
#define snd second
typedef vector<int> vi;typedef vector<vi> vvi;typedef pair<int,int> pii;typedef vector<pii> vpii;
typedef long long ll;

void out(vi &as, vi &bs) {
  rep(i, SZ(as)) {
    _p(i+1<SZ(as)?"%d ":"%d\n", as[i]);
  }

  _p("%d\n", SZ(bs));
  rep(i, SZ(bs)) {
    _p(i+1<SZ(bs)?"%d ":"%d\n", bs[i]);
  }
}

void Main() {
  int N, M;
  scanf("%d%d", &N, &M);
  vi A(M);
  rep(i, M) scanf("%d", &A[i]);

  if (M == 1) {
    if (N == 1) {
      out(A, A);
    }
    else {
      vi bs {N-1, 1};
      out(A, bs);
    }
    return;
  }

  vi os, es;
  rep(i, M) {
    (A[i] % 2 ? os : es).push_back(A[i]);
  }

  if (SZ(os) >= 3) {
    puts("Impossible");
    return;
  }

  vi as;
  if (SZ(os)) as.push_back(os[0]);
  forr(e, es) as.push_back(e);
  if (SZ(os) == 2) as.push_back(os[1]);

  vi bs(as);
  bs[0]--;
  bs[SZ(bs)-1]++;
  vi cs;
  forr(b, bs) if (b != 0) cs.push_back(b);
  out(as, cs);
}
int main() { cin.tie(0); ios::sync_with_stdio(false); Main(); return 0; }
