#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename T>
struct BinaryIndexedTree{
   vector<T> data;
   BinaryIndexedTree(int sz){
       data.assign(sz+1, 0);
   }
   // 区間[0,k]の合計 sum(v[0]~v[k])
   T sum(int k){
       T ret=0;
       for(++k;k>0;k-=(k&-k)) ret+=data[k];
       return ret;
   }
   // v[a]+=x
   void add(int k,T x){
       for(++k;k<data.size();k+=(k&-k)) data[k]+=x;
   }
   // wを超える最小のv[i]のiを返す(0indexedのを返す)(data上のindexを返したいならreturn x+1)
   int lower_bound(T w){//T?
       if(w<=0) return 0;
       //左右どっちに行くか考える
       int x=0,r=1;
       while(r<data.size()) r<<=1;
       for(int k=r;k>0;k>>=1){
           if(x+k<=data.size()&&data[x+k]<w){
               //左部分を引いて右へ，再起っぽい
               w-=data[x+k];
               x+=k;
           }
       }
       // return x+1;
       return x;
   }
};


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        a[i]-=k;
    }
    vector<ll> sum(n+1,0);
    rep(i,n) sum[i+1]=sum[i]+a[i];
    map<ll,int> id;
    vector<ll> sub=sum;
    sort(ALL(sub));
    int cnt=1;
    rep(i,n+1){
        if(id.count(sub[i])) continue;
        id[sub[i]]=cnt;cnt++;
    }
    BinaryIndexedTree<ll> BIT(cnt+10);
    rep(i,n+1){
        BIT.add(id[sum[i]],1);
    }
    ll ans=0;
    rep(i,n){
        BIT.add(id[sum[i]],-1);
        //id[sum[i]]以上のものを数えたい
        ans+=BIT.sum(cnt+5)-BIT.sum(id[sum[i]]-1);
    }
    cout<<ans<<endl;
    return 0;
}
