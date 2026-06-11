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

const int SIZE = 212345;
ll a0[SIZE];
ll a1[SIZE];

// 範囲add : [l, r] それぞれに x を加える
void add(int l, int r, ll x) {
  l++;
  r++;
  a0[l] += -x*(l-1);
  a1[l] += x;
  a0[r+1] += x*r;
  a1[r+1] += -x;
}
// sum[0, i]
ll get(int i) {
  i++;
  return a1[i] * i + a0[i];
}
 
const int MAX_N = 112345;
int a[MAX_N];
 
int main2() {
  CLR(a0, 0);
  CLR(a1, 0);
 
  int N = nextInt();
  int M = nextInt(); 
  REP(i, N) a[i] = nextInt() -1;
 
  ll ans = 0;
  for (int i = 0; i + 1 < N; i++) {
    const int L = (a[i] <= a[i+1] ? a[i+1] - a[i] : a[i+1] - a[i] + M);
    ans += L;
    if (L >= 2) {
      if (a[i] < a[i+1]) {
        add(a[i]+2, a[i+1], 1); add(a[i+1]+1, a[i+1]+1, -(L-1));
      } else {
        if (a[i]+2 <= M-1) {
          add(a[i]+2, M-1, 1);
          add(M, M, -(M-a[i]-2));
          add(0, 0, M-a[i]-2);
          add(0, a[i+1], 1);
          add(a[i+1]+1, a[i+1]+1, -(L-1));
        } else {
          add(a[i]+2-M, a[i+1], 1);
          add(a[i+1]+1, a[i+1]+1, -(L-1));
        }
      }
      // for (int x = 0; x <= M; x++) cout << get(x) << " "; cout << endl;
    }
  }

  for (int i = 1; i < MAX_N; i++) a0[i] += a0[i-1];
  for (int i = 1; i < MAX_N; i++) a1[i] += a1[i-1];

  ll ma = 0;
  for (int x = 0; x <= M; x++) {chmax(ma, get(x));}
  ans -= ma;
  cout << ans << endl;
  return 0;
}

int main() { 
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
