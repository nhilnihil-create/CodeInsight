#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);i++)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> void chmin(T& t, const U& u){if(t>u)t=u;}
template<typename T,typename U> void chmax(T& t, const U& u){if(t<u)t=u;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T mpow(T a, T n) {
   T res = 1;
   for(;n;n>>=1) {
      if (n & 1) res = res * a;
      a = a * a;
   }
   return res;
}

//cin.tie(0);ios::sync_with_stdio(false);
//cout<<fixed<<setprecision(20);

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//cin.tie(0);ios::sync_with_stdio(false);
//cout<<fixed<<setprecision(20);


template<typename T> 
struct BIT{
  int n;
  vector<T> bit;//1-indexed

  BIT():n(-1){}
  //initialization

  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  //initialization2 n_要素数 d初期値
  
  T sum(int i){
    T s=bit[0];
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  //1からiまでの和(1-indexed)
  
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
  //iにa加える
  
  T lower_bound(T w){
    if(w<=0) return 0;
    T x=0,r=1;//xは横の位置を管理するイメージ
    while(r<n) r<<=1;
    for(T k=r;k>0;k>>=1){//上の層から見る
      if(x+k<=n && bit[x+k]<w){
        w-=bit[x+k];
        x+=k;//右の要素に移る
      }
    }
    return x+1;
  }
  //indまでの区間和がw以上になるような最小のindを求める
  
  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
  }//0-index用

  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }//[l,r)の和を求める

  T query0(int l,int r){
    return sum(r)-sum(l);
  }//0-index用
};

signed main(){
    ll n,k,ans=0;cin>>n>>k;
    
    vector<ll> v(n),sum(n,0);
    rep(i,0,n){
        cin>>v[i];
        v[i]=v[i]-k;
        if(i>0)sum[i]=sum[i-1]+v[i];
        else sum[0]=v[i];

        if(sum[i]>=0)ans++;
    }

    vector<ll> ind=sum;
    sort(all(ind));
    map<ll,ll> ma;
    rep(i,0,n){
        ma[ind[i]]=i+1;
    }

    BIT<ll> b(n,0);

    rep(i,0,n){
        ans+=b.query(0,ma[sum[i]]+1);
        b.add(ma[sum[i]],1); 
        //cerr<<ans<<endl;
    }
    cout<<ans<<endl;

}   
