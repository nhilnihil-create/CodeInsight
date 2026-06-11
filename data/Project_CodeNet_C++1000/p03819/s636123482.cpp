#include <cassert>
#include "limits.h"
#include <limits>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <memory>
#include <utility>
 
#define rep(i, a, b) for (long long (i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void debug_out(){std::cerr<<std::endl;}

template<typename H,typename... T>
void debug_out(H head,T... tail){
  std::cerr<<" "<<head;
  debug_out(tail...);
}

 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
long long pow_mod(long long a, long long b, long long mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }
 
  long long x = 1;
 
  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}
 
const long long MOD = 998244353;
// const long long MOD = 1e9 + 7;

using ll = long long;
using P = std::pair<long long,long long>;

//遅延セグ木
template<typename T,typename E>
class LazySegmentTree{
  private:
  int n,n0;
  std::vector<T> dat;
  std::vector<E> lazy;

  T init_t;
  E init_e;

  using F=std::function<T(T,T)>;
  using G=std::function<T(T,E)>;
  using H=std::function<E(E,E)>;
  using P=std::function<E(E,int)>;

  F f;
  G g;
  H h;
  P p;

  T update(int a,int b,E val,int l,int r,int k){
    if(lazy[k]!=init_e){
      if(k<n0-1){
        lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
        lazy[2*k+2]=h(lazy[2*k+2],lazy[k]);
      }
      dat[k]=g(dat[k],p(lazy[k],r-l));
      lazy[k]=init_e;
    }

    if(r<=a||b<=l)return dat[k];
    if(a<=l&&r<=b){
      lazy[k]=h(lazy[k],val);
      return g(dat[k],p(lazy[k],r-l));
    }

    return dat[k]=f(update(a,b,val,l,l+(r-l)/2,2*k+1),update(a,b,val,l+(r-l)/2,r,2*k+2));
  }

  T query(int a,int b,int l,int r,int k){
    if(lazy[k]!=init_e){
      if(k<n0-1){
        lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
        lazy[2*k+2]=h(lazy[2*k+2],lazy[k]);
      }
      dat[k]=g(dat[k],p(lazy[k],r-l));
      lazy[k]=init_e;
    }

    if(r<=a||b<=l)return init_t;
    if(a<=l&&r<=b)return dat[k];
    T lval=query(a,b,l,l+(r-l)/2,2*k+1);
    T rval=query(a,b,l+(r-l)/2,r,2*k+2);
    return f(lval,rval);
  }

  public:

  LazySegmentTree(int n_,F f_,G g_,H h_,T t,E e,std::vector<T> dat_=std::vector<T>(),P p_=[](E a,int n){return a;})
    :n(n_),init_t(t),init_e(e),f(f_),g(g_),h(h_),p(p_){

    n0=1;
    while(n0<n)n0<<=1;
    dat=std::vector<T>(2*n0-1,init_t);
    lazy=std::vector<E>(2*n0-1,init_e);
    if(n_==dat_.size()){
      for(int i=0;i<n_;i++)dat[i+n0-1]=dat_[i];
      for(int i=n0-2;i>=0;i--)dat[i]=f(dat[2*i+1],dat[2*i+2]);
    }
  }

  void update(int a,int b,E val){
    update(a,b,val,0,n0,0);
  }

  T query(int a,int b){
    return query(a,b,0,n0,0);
  }
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n,m;
  std::cin>>n>>m;

  std::vector<P> seg(n);
  rep(i,0,n){
    ll l,r;
    std::cin>>l>>r;
    r++;
    seg[i]={l,r};
  }

  std::sort(all(seg),[](const P& a,const P& b)->bool{
    return a.second-a.first<b.second-b.first;
  });

  auto plus=[](const ll& a,const ll& b){return a+b;};
  LazySegmentTree<ll,ll> segtree(m+1,plus,plus,plus,0,0,std::vector<ll>(0),[](ll a,int b){return a*b;});

  ll now=0;
  rep(i,1,m+1){
    while(now<n&&(seg[now].second-seg[now].first)<i){
      segtree.update(seg[now].first,seg[now].second,1);
      now++;
    }
    ll ans=n-now;
    for(ll j=0;j<=m;j+=i){
      ans+=segtree.query(j,j+1);
    }

    std::cout<<ans<<"\n";
  }

  return 0;
}