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

ll A[112345];
ll D[112345];

bool solve(ll N) {
  ll M = (N+1)*N/2;
  ll S = accumulate(A, A+N, 0LL);
  if (S % M != 0) return false;
  ll K = S / M; // ちょうど K 回操作する
  REP(i, N) {
    D[i] = A[(i+1) % N] - A[i];
  }

  REP(i, N) D[i] -= K;

  ll kk = 0;
  REP(i, N) {
    if (D[i] % N != 0) return false;
    if (D[i] > 0) return false;
    else kk -= D[i] / N;
  }
  return kk == K;
}

int main2() {
  int N = nextInt();
  REP(i, N) A[i] = nextInt();

  bool ans = solve(N);
  cout << (ans?"YES":"NO") << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}