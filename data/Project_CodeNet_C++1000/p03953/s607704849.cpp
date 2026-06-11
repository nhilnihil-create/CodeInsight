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
const int MAX_M = 112345;

int N, M;
ll X[MAX_N];
ll A[MAX_M];

ll D[MAX_N];
ll B[MAX_N];
ll BB[MAX_N];
ll tmp[MAX_N];

void apply(ll* D, ll *B) {
  REP(i, N) tmp[i] = D[B[i]];
  REP(i, N) D[i] = tmp[i];
}

int main2() {
  N = nextInt();
  REP(i, N) X[i] = nextInt();
  M = nextInt();
  ll K = nextLong();
  REP(i, M) A[i] = nextInt()-1;

  D[0] = X[0];
  REP(i, N-1) D[i+1] = X[i+1] - X[i];

  REP(i, N) B[i] = i;
  REP(i, M) swap(B[A[i]], B[A[i]+1]);
  REP(i, N) BB[i] = B[i];

  REP(i, 60) {
    if (K >> i & 1) {
      apply(D, B);
    }
    apply(BB, B);
    REP(i, N) B[i] = BB[i];
  }

  X[0] = D[0];
  REP(i, N-1) {
    X[i+1] = D[i+1] + X[i];
  }
  REP(i, N) printf("%lld\n", X[i]);
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}