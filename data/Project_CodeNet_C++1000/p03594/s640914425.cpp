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


int f(int h, int w, int d) {
  const int mod = 2*d;
  h = (h % mod + mod) % mod;
  w = (w % mod + mod) % mod;

  int res = 0;
  if (h >= d) res += 1;
  if (w >= d) res += 2;
  return res;
}

char t[510][510];

bool check(int H, int W, int d) {
  REP(i1, H) REP(j1, W) {
    REP(i2, H) REP(j2, W) {
      if (abs(i1 - i2) + abs(j1 - j2) == d) {
        if (t[i1][j1] == t[i2][j2]) {
          return false;
        }
      }
    }
  }
  return true;
}

int main2() {
  int H = nextLong();
  int W = nextLong();
  int d = nextLong();

  REP(i, H) {
    REP(j, W) {
      t[i][j] = "RGBY"[f(i+j, i-j, d)];
    }
  }

  REP(i, H) {
    REP(j, W) cout << t[i][j];
    cout << '\n';
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