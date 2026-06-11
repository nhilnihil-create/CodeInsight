#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>
#include <set>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<int,int>;
const ll M = 1e9+7, mx = 200000;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}

const int up[]={1,-1,0,0}, lf[]={0,0,1,-1};
bool vaild(int x, int y, int hh, int ww){return 0<=x&&x<hh&&0<=y&&y<ww;}

template <typename T>
struct seg_Lp {
  // 区間更新、一点取得
  using F = function<T(T,T)>;
  const F f,g; const T ft; vector<T> lazy; int m, n, n2;
  seg_Lp(int _m, F _f, T _ft) : m(_m), f(_f), ft(_ft) {
    n=1; while(m>n) n<<=1;
    n2=2*n; lazy.resize(n2);
    for(int i=1;i<n2;i++) lazy[i]=ft;
  }

  // 増加
  void update(int k, int a, int b, int v, int l, int r) {
    if (a <= l && r <= b) {lazy[k] = f(lazy[k],v); return;}
    else if (a >= r || b <= l) return;
    else {
      update(2*k, a, b, v, l, (l+r)/2);
      update(2*k+1, a, b, v, (l+r)/2, r);
    }
  }

  // 増加（使用用）
  void update(int a, int b, int v) {
    update(1, a, b, v, 0, n);
  }

  // 合計
  T sum(int k) {
    //int fir = sum[k];
    k+=n;
    int ins = lazy[k];
    while(k>0) {
      k = k / 2;
      ins = f(ins,lazy[k]);
    }
    return ins; 
  }
  void print() {
    for(int i=1,j=0;i<n2;i++) {
      if (i+1 > (1<<j)) {cout<<endl; j++;}
      cout<<lazy[i]<<" ";
    } cout<<endl;
  }
};

struct tup {
  int x,y,c;
  bool operator<(const tup tt) const {
    if (c != tt.c) return c < tt.c;
    else if (x != tt.x) return x < tt.x;
    else return y < tt.y;
  }
  bool operator>(const tup tt) const {
    if (c != tt.c) return c > tt.c;
    else if (x != tt.x) return x > tt.x;
    else return y > tt.y;
  }
};

int main() {
  int n,m; cin>>n>>m;
  tup tp[n];
  for(int i=0;i<n;i++) cin>>tp[i].x>>tp[i].y;
  for(int i=0;i<n;i++) {
    tp[i].c=tp[i].y-tp[i].x+1;
  }
  sort(tp,tp+n);
  seg_Lp<int> sg(m+1,[](ll a,ll b){return a+b;},0);
  for(int i=1,j=0;i<=m;i++) {
    int an = n-j;
    for(int k=i;k<=m;k+=i) {
      an+=sg.sum(k);
    }
    cout<<an<<endl;
    while(j<n && tp[j].c <= i) {
      sg.update(tp[j].x,tp[j].y+1,1); j++;
    }
    //sg.print();
  }
}