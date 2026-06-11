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

int nextInt() { int x; scanf("%d", &x); return x;}
ll nextLong() { ll x; scanf("%lld", &x); return x;}

const int MAX_N = 112345;
int T[MAX_N];
int A[MAX_N];

ll hi[MAX_N];
ll lo[MAX_N];

void update(int i, ll from, ll to) {
  chmin(hi[i], to);
  chmax(lo[i], from);
}

int main2() {
  ll N = nextLong();
  REP(i, N) T[i] = nextInt();
  REP(i, N) A[i] = nextInt();

  const int INF = 1001001001;
  REP(i, N) hi[i] = INF;
  REP(i, N) lo[i] = 0;


  update(0, T[0], T[0]);
  for (int i = 1; i < N; i++) {
    if (T[i-1] < T[i]) {
      update(i, T[i], T[i]);
    } else {
      update(i, 1, T[i]);
    }
  }

  update(N-1, A[N-1], A[N-1]);
  for (int i = N-2; i >= 0; i--) {
    if (A[i] > A[i+1]) {
      update(i, A[i], A[i]);
    } else {
      update(i, 1, A[i]);
    }
  }
  const ll MOD = (ll)(1e9 + 7);
  ll ans = 1;
  REP(i, N) {
    if (lo[i] <= hi[i])
      ans *= hi[i] - lo[i] + 1;
    else
      ans = 0;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
