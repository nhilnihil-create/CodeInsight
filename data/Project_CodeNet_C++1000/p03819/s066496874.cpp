#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;

template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;

  SegmentTree(){}
  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){
    if(a>=b) return ti;
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?k-n:-1;
    }
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }

  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
  //アウトの条件を渡す
};

signed main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>>v(N);
    REP(i, N) {
        cin >> v[i].first >> v[i].second;
    }
    sort(ALL(v));
    vector<vector<int>>ls(M + 1);
    vector<vector<int>>rs(M + 2);
    vector<int>start(M + 1, N);
    RREP(i, N) {
        start[v[i].first] = i;
        ls[v[i].first].emplace_back(i);
        rs[v[i].second + 1].emplace_back(i);
    }
    RREP(i, M) CHMIN(start[i], start[i + 1]);
    SegmentTree<int>seg([](int a, int b){return a + b;},0);
    seg.build(vector<int>(N));
    vector<vector<int>>primes(M + 1);
    for(int i = 1; i < M + 1; i++) {
        for(int j = i; j < M + 1; j += i) {
            primes[j].emplace_back(i);
        }
    }
    vector<int>ans(M + 1);
    FOR(i, 1, M + 1) {
        for(auto idx : ls[i]) {
            seg.set_val(idx, 1);
        }
        for(auto idx : rs[i]) {
            seg.set_val(idx, 0);
        }
        for(auto p : primes[i]) {
            int l = start[i - p + 1];
            ans[p] += seg.query(l, N);
        }
    }
    FOR(i, 1, M + 1) out(ans[i]);
}