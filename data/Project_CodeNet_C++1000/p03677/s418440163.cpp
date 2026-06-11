#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }
    ll sum=0;
    vector<vector<int>> in(m+m),out(m+m);

    rep(i,n-1){
        if(a[i]<a[i+1]) sum+=a[i+1]-a[i];
        else            sum+=a[i+1]+m-a[i];

        if(a[i+1]-a[i]==1) continue;
        if(a[i]<a[i+1]){
            in[a[i]+2].push_back(i);
            out[a[i+1]].push_back(a[i+1]-a[i]-1);
        }else{
            in[a[i]+2].push_back(i);
            out[a[i+1]+m].push_back(a[i+1]+m-a[i]-1);
        }
    }

    vector<ll> profit(m,0);
    ll cnt=0,num=0;
    rep(i,m+m){
        cnt+=(ll)in[i].size();
        num+=cnt;
        profit[i%m]+=num;
        for(auto x:out[i])num-=x;
        cnt-=(ll)out[i].size();
    }
    cout<<sum-(*max_element(ALL(profit)))<<endl;
    return 0;
}
