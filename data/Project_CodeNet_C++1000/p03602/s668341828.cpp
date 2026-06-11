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

const int MAX_N = 301;
ll A[MAX_N][MAX_N];
ll D[MAX_N][MAX_N];

int main2() {
  int N = nextInt();
  REP(i, N) REP(j, N) A[i][j] = nextInt();
  REP(i, N) REP(j, N) D[i][j] = A[i][j];

  REP(k, N) REP(i, N) REP(j, N) {
    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
  }

  bool possible = true;
  REP(i, N) REP(j, N) if (A[i][j] != D[i][j]) {
    possible = false;
  }

  if (!possible) {
    cout << -1 << endl;
    return 0;
  }

  ll INF = 1LL << 58;
  ll ans = 0;
  REP(i, N) REP(j, N) if (i < j) {
    ll min_d = INF;
    REP(k, N) if (k != i && k != j) {
      chmin(min_d, A[i][k] + A[k][j]);
    }
    if (A[i][j] != min_d) {
      ans += A[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
