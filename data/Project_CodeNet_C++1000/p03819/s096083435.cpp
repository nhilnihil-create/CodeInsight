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

typedef pair<int,int> P;

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

const int MAX_N = 312345;
const int MAX_M = 112345;
P ps[MAX_N];
int ans[MAX_M];

int len(P p) {
  return p.second - p.first + 1;
}

int main2() {
  int N = nextInt();
  int M = nextInt();
  REP(i, N) {
    int a = nextInt();
    int b = nextInt();
    ps[i] = {a, b};
  }
  sort(ps, ps + N, [](const P &a, const P& b){
    return len(a) < len(b);
  });

  BIT bit(M+10);

  int pi = 0;
  for (int d = 1; d <= M; d++) {
    while (pi < N && len(ps[pi]) < d) {
      bit.add(ps[pi].first,      +1);
      bit.add(ps[pi].second + 1, -1);
      pi++;
    }
    int res = N - pi;
    for (int k = 0; k <= M; k += d) {
      res += bit.range(k);
    }
    ans[d] = res;
  }

  for (int d = 1; d <= M; d++) {
    printf("%d\n", ans[d]);
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
