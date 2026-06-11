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

const int MAX_N = 112345;
int a[MAX_N];

int main2() {
  int N = nextInt();
  int T = nextInt();
  REP(i, N) a[i] = nextInt();
  const int INF = 1001001001;

  int min_val = INF;

  int stride = 0;
  int count = 0;
  REP(i, N) {
    if (min_val > a[i]) {
      min_val = a[i];
    } else {
      int d = a[i] - min_val;
      if (stride < d) {
        stride = d;
        count = 1;
      } else if (stride == d) {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
