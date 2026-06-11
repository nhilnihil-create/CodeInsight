#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;

template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;//二項演算
  T ti;//単位元
  vector<T> dat;

  SegmentTree(){}
  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){//sizeがn_のsegtreeを作る
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){//vによってsegtreeをbuildする
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){//k番目をxにする
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){//区間[a,b)に対しFを適応した値を返す
    if(a>=b) return ti;
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){//
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
};

int n,m;
vector<PP> sec;

void solve(){
  cin >> n >> m;
  sec.push_back(PP(m+4,P(0,0)));
  rep(i,n){
    int l,r;cin >> l >> r;
    sec.push_back(PP(r-l+1,P(l,r+1)));
  }
  sort(sec.begin(),sec.end());
  auto f=[](int a,int b){return a+b;};
  SegmentTree<int> seg(f,0);
  seg.init(m+2);
  int k=0;
  Rep(i,1,m+1){
    while(sec[k].first==i-1){
      int l,r;l=sec[k].second.first;r=sec[k].second.second;
      //cout << l << " " << r << endl;
      seg.set_val(l,seg.query(l,l+1)+1);
      seg.set_val(r,seg.query(r,r+1)-1);
      k++;
    }
    int ans=n-k;
    for(int d=i;d<=m;d+=i){
      ans+=seg.query(0,d+1);
    }
    cout << ans << endl;
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}