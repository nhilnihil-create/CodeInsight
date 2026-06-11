#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    ll n;cin>>n;
    vl a(3*n);rep(i,3*n)cin>>a[i];
    vl l(3*n,-LINF);
    ll sum=0;
    priority_queue<ll,vl,greater<ll>> pq1;
    rep(i,n){
        sum+=a[i];
        pq1.push(a[i]);
    }
    //cout<<sum<<endl;
    l[n-1]=sum;
    for(int i=n;i<2*n;i++){
        sum+=a[i];
        pq1.push(a[i]);
        ll num=pq1.top();
        pq1.pop();
        sum-=num;
        l[i]=sum;
    }
    vl r(3*n,LINF);
    priority_queue<ll,vl> pq2;
    sum=0;
    for(int i=3*n-1;i>=2*n;i--){
        sum+=a[i];
        pq2.push(a[i]);
    }
    r[2*n]=sum;
    for(int i=2*n-1;i>=n;i--){
        sum+=a[i];
        pq2.push(a[i]);
        ll num=pq2.top();
        pq2.pop();
        sum-=num;
        r[i]=sum;
    }
    ll ans=-LINF;
    
    for(int i=n-1;i<=2*n-1;i++){
        //cout<<"i: "<<i<<endl;
        //cout<<l[i]<<" "<<r[i+1]<<endl;
        chmax(ans,l[i]-r[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}