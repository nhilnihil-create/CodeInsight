#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

ll nextLong() { ll x; scanf("%lld", &x); return x;}

int main2() {
  ll N = nextLong();
  ll L = nextLong();
  ll T = nextLong();

  vector<ll> X(N), W(N);
  REP(i, N) {
    X[i] = nextLong();
    W[i] = nextLong();
  }

  vector<ll> Y(N);
  REP(i, N) {
    if (W[i] == 1) Y[i] = (X[i] + T) % L;
    if (W[i] == 2) Y[i] = ((X[i] - T) % L + L) % L;
  }

  ll Y0 = Y[0];
  sort(ALL(Y));

  ll d = 0;
  for (int i = 1; i < N; i++) {
    if (W[0] == 1 && W[i] == 2) {
      ll t = 2 * T;
      if (t >= abs(X[i] - X[0])) {
        d++;
        t -= abs(X[i] - X[0]);
      }
      d += max(0LL, t / L);
    }
    if (W[0] == 2 && W[i] == 1) {
      ll t = 2 * T;
      if (t >= L - abs(X[i] - X[0])) {
        d++;
        t -= L - abs(X[i] - X[0]);
      }
      d += max(0LL, t / L);
    }
  }
  // cout << "d=" << d << endl;
  d %= N;

  vector<ll> ans(N);

  if (W[0] == 1) {
    int y0 = prev(upper_bound(ALL(Y), Y0)) - Y.begin();
    REP(i, N) ans[(d + i) % N] = Y[(y0 + i) % N];
  } else {
    int y0 = (lower_bound(ALL(Y), Y0)) - Y.begin();
    REP(i, N) ans[(N - d + i) % N] = Y[(y0 + i) % N];
  }

  REP(i, N) {
    cout << ans[i] << '\n';
  }
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}