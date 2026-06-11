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

//うまく0の時をはじけてない
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;cin>>n;
    vector<ll> a(n),b(n),mt(n,-1);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];

    bool f=true;
    if(a[0]>b[0])f=false;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            if(a[i]>b[i])f=false;
        }
    }

    if(b[n-1]>a[n-1])f=false;
    for(int i=n-2;i>=0;i--){
        if(b[i]!=b[i+1]){
            if(b[i]>a[i])f=false;
        }
    }
    if(!f){
        cout<<0<<endl;return 0;
    }








    ll nw=0;
    rep(i,n){
        if(nw!=a[i]){
            mt[i]=a[i];
            nw=a[i];
        }
    }

    if(mt[n-1]>0&&mt[n-1]!=b[n-1]){
        cout<<0<<endl;return 0;
    }
    mt[n-1]=b[n-1];
    for(int i=n-2;i>=0;i--){
        if(b[i+1]!=b[i]){
            if(mt[i]<0){
                mt[i]=b[i];
                nw=b[i];
            }
            else{
                if(mt[i]!=b[i]){
                    cout<<0<<endl;return 0;
                }
            }
        }
    }

    ll l=mt[0],cnt=0,ans=1ll;
    for(int i=1;i<n;i++){
        if(mt[i]<0){
            cnt++;
            continue;
        }
        ll mul=min(mt[i],l);
        rep(_,cnt){
            ans=(ans*mul)%mod;
        }
        l=mt[i];
        cnt=0;
    }
    cout<<ans<<endl;
    return 0;
}
