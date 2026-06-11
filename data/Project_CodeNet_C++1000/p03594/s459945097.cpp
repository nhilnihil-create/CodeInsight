#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>bool chmin(T&a,const T&b){return a>b?(a=b,1):0;}
template<class T>bool chmax(T&a,const T&b){return a<b?(a=b,1):0;}


int nextInt() { int x; scanf("%d", &x); return x;}

int color[512][512];

int main2() {
  int H = nextInt();
  int W = nextInt();
  int d = nextInt();
  memset(color, -1, sizeof(color));
  string s = "RYGB";
  
  if (d % 2 == 1) {
    REP(i, H) REP(j, W) color[i][j] = (i + j) % 2;  
    REP(i, H) {
      REP(j, W) cout << s[color[i][j]];
      cout << endl;
    }
    return 0;
  } else {
    REP(i, H) REP(j, W) {
      int x = (i + j) / d % 2;
      int y = (i - j + 1000*d) / d % 2;
      color[i][j] = (x << 1) + y;
    }
    REP(i, H) {
      REP(j, W) cout << s[color[i][j]];
      cout << endl;
    }
    return 0;
  }
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws) main2();
  return 0;
}

