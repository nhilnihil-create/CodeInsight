#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<typename T>
struct BIT{
    //1-index
    //0-indexで取ると無限ループする
    private:
    V<T> arr;
    int n;

    public:
    BIT(int siz){
        n=siz;
        arr.assign(n+1,0);
    }
    //一点更新 aにvを加える
    void add(T a,T v){
        //x+=(x&-x) 初項a,それ以降a<=2^Nが列挙
        for(T x=a;x<=n;x+=(x&-x)){
            arr[x]+=v;
        }
    }
    T sum(T a){
        // 1からaまでの区間和
        T ret=0;
        for(T x=a;x>0;x-=(x&-x))ret+=arr[x];
        return ret;
    }
    T get(T x){//x番目に大きい数　// 区間和がw以上となる最小のindを返す
        if(x<=0) return 0;
        T N=1;
        while(N*2<=n)N*=2;
        T v=0;
        for(T i=N;i>0;i/=2){
            if(v+i<=n&&arr[v+i]<x){
                x-=arr[v+i];
                v+=i;
            }
        }
        return v+1;
    }
    T query(int l,int r){
        return sum(r)-sum(l);
    }
};
map<ll,ll> mp;
int main(){
  ll n,k;
  cin>>n>>k;
  V<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  V<ll> sum(n+1);
  for(int i=0;i<n;i++)sum[i+1]=sum[i]+a[i];
  V<ll> d;
  int cnt=1;
  for(int i=0;i<=n;i++)d.emplace_back(sum[i]-k*i);
  sort(all(d));
  for(int i=0;i<=n;i++){
    if(!mp.count(d[i]))mp[d[i]]=cnt++;
  }
  BIT<ll> t(cnt+5);
  ll ans=0;
  for(int i=0;i<=n;i++){
    ans+=t.query(0,mp[sum[i]-i*k]);
    t.add(mp[sum[i]-i*k],1);
  }
  cout<<ans<<"\n";
}