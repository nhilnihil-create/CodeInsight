#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};


struct Timer{
    chrono::system_clock::time_point start, end;
    Timer(){ start = chrono::system_clock::now(); }
    ~Timer(){
        end = chrono::system_clock::now();
        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr<<"time : "<<msec<<" ms"<<endl;
    }
};



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Timer TM;

    ll n,k,a[100010];
    ll sum[100010]={};
    cin>>n>>k;
    rep(i,n){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    ll dp1[100010]={},dp2[100010]={};
    rep(i,n){
        if(a[i]>0) dp1[i+1]=dp1[i]+a[i];
        else dp1[i+1]=dp1[i];
    }
    repr(i,n){
        if(a[i]>0) dp2[i]=dp2[i+1]+a[i];
        else dp2[i]=dp2[i+1];
    }
    ll ans=0;
    /*
    rep(i,n+1) cout<<sum[i]<<" ";
    cout<<endl;
    rep(i,n+1) cout<<dp1[i]<<" ";
    cout<<endl;
    rep(i,n+1) cout<<dp2[i]<<" ";
    cout<<endl;
    */
    rep(i,n-k+1){
        ll cnt=0;
        ll s=sum[i+k]-sum[i];
        cnt+=dp1[i]+dp2[i+k];
        // cout<<cnt<<endl;
        ans=max(ans,cnt+s);
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}