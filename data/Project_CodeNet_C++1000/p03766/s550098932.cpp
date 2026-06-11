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
void add(ll& x, ll y) {x+=y; x%=M;}; void mul(ll& x, ll y) {x*=y; x%=M;}; void chmax(ll& x, ll y) {if (x<y) x=y;}; void chmin(ll& x, ll y) {if (x>y) x=y;};

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
  void print2() {
    for(int i=0;i<m;i++) {
      cout<<sum(i)<<" ";
    } cout<<endl;
  }
};

int main() {
  ll n; cin>>n;
  seg_Lp<ll> sg(n, [](ll x,ll y){return (x+y)%M;}, 0);
  sg.update(0,1,1);

  ll an = 0;
  for(int i=0;i<n;i++) {
    ll nw = sg.sum(i);
    if (i == n-1) {
      // 3 1 1 1 ? -> ? はなんでも良い
      an += nw * n;
      break;
    }
    // 2 1 1 ? -> 1
    //sg.print2();
    sg.update(i+1,i+2,nw);
    //sg.print2();

    // 2 1 1 ? -> (2 ~ n), (2 ~ n...)
    an += nw * (n-1) % M * (n-1) % M;
    //caut(nw*(n-1)*(n-1));

    // 2 1 1 ? -> (2 ~ n), (1,1,1,1)
    sg.update(i+3,n,nw); // 2 1 1 ?
    //an += nw * (i+1);
    an += nw * (i+2) % M;

    if (i == n-2) an -= nw - M; // 右端手前n-1が1なのは計算済み
    //caut(nw*(i+2));
    an %= M;
    //sg.print2();
    //cout<<an<<endl;
  }
  an %= M;
  cout<<an<<endl;
}