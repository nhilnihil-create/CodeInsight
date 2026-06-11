#include <bits/stdc++.h>
using namespace std;

#define int long long
#define times(n, i) uptil(0, n, i)
#define uptil(a, b, i) for(int i = (a); i < (b); ++i)
#define all(v) begin(v), end(v)

inline int moda(int a, int b) { int m = a % b; return m + (m >= 0 ? 0 : b); }

template<class T>
ostream& operator<<(ostream& o, const vector<T>& v) { for(T t: v) o << t << ','; return o; }


signed main() {
// NLTN(XW)
int N;int L;int T;cin>>N;cin>>L;cin>>T;vector<int> X(N);vector<int> W(N);times(N,Ri_0){cin>>X[Ri_0
];cin>>W[Ri_0];}

  bool rev = W[0] == 2;
  if(rev) {
    times(N, i) {
      X[i] = moda(-X[i], L);
      W[i] = 3 - W[i];
    }
  }

  // 元1がぶつかる回数
  int n_hit = 0;
  uptil(1, N, i) {
    if(W[i] == 2) {
      n_hit += T * 2 / L + (T * 2 % L > moda(X[i] - X[0], L));
      cerr << i << ' ' << n_hit << endl;
    }
  }

  vector<int> lx(N);
  times(N, i) lx[i] = moda(X[i] + (W[i] == 1 ? T : -T), L);
  int lx_sp = lx[0];
  sort(all(lx));
  int spi = distance(begin(lx), find(all(lx), lx_sp));

  int i0 = spi - n_hit;

  cerr << n_hit << ' ' << lx_sp << ' ' << spi << ' ' << i0 << endl << lx << endl;

  if(rev) {
    i0 = -1 - i0;
    reverse(all(lx));
    times(N, i) lx[i] = moda(-lx[i], L);
  }
  cerr << lx << endl;

  times(N, i) {
    // cerr << i0 + i << ' ' << N << endl;
    cout << lx[moda(i0 + i, N)] << endl;
  }

  return 0;
}
