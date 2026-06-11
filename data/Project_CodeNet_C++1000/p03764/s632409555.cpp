#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,x[100010],y[100010],a[100010],b[100010],Ysum=0;
    ll X[100010],Y[100010],ans=0;
    cin>>n>>m;
    rep(i,n) cin>>x[i];
    rep(i,m) cin>>y[i];
    rep(i,n-1){
        a[i]=(i+1)*(n-1-i)%MOD;
        // cout<<a[i]<<endl;
    }
    rep(i,m-1){
        b[i]=(i+1)*(m-1-i)%MOD;
        // cout<<b[i]<<endl;
    }
    rep(i,n-1){
        X[i]=(x[i+1]-x[i])*a[i];
        X[i]%=MOD;
        // cout<<X[i]<<endl;
    }
    rep(i,m-1){
        Y[i]=(y[i+1]-y[i])*b[i];
        Y[i]%=MOD;
        Ysum+=Y[i];
        // cout<<Y[i]<<endl;
    }
    Ysum%=MOD;
    // cout<<endl;
    rep(i,n-1){
        ans+=(X[i]*Ysum);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}