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

struct BIT {
  int n;
  vector<ll> tree;
  BIT(int n):n(n),tree(n+1) {} 
  void fill(ll val) {
    REP(i, n+1) tree[i] = (i&-i) * val;
  }
  void add(int idx, ll val) {
    for (int x=idx+1; x<=n; x+=x&-x) tree[x] += val;
  }
  // sum[0, idx]
  ll range(int idx) {
    ll sum=0;
    for (int x=idx+1; x>0; x-=x&-x) sum += tree[x];
    return sum;
  }
  // sum[a, b]
  ll range(int a, int b) {
    return range(b) - range(a - 1);
  }
};

const int SIZE = 212345;
BIT bit0(SIZE);
BIT bit1(SIZE);
// 範囲add : [l, r] それぞれに x を加える
void add(int l, int r, ll x) {
  bit0.add(l, -x*(l-1));
  bit1.add(l, x);
  bit0.add(r+1, x*r);
  bit1.add(r+1, -x);
}
// sum[0, i]
ll get(int i) {
  return bit1.range(i) * i + bit0.range(i);
}

const int MAX_N = 112345;
int a[MAX_N];

int main2() {
  bit0.fill(0);
  bit1.fill(0);

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
