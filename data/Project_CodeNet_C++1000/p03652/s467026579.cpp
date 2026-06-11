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
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    ll n,m;
    cin>>n>>m;
    V<V<ll>> a(n,V<ll>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    int ans=INT_MAX; 
    V<ll> ind(n,0);
    V<bool> used(m+1,false);
    for(int i=0;i<m;i++){
        V<int> res(m+1,0);
        for(int j=0;j<n;j++){
           res[a[j][ind[j]]]++;
        }
        int id=0,ma=0;
        for(int j=1;j<=m;j++){
            if(chmax(ma,res[j])){
                id=j;
            }
        }
        chmin(ans,ma);
        used[id]=true;
        for(int j=0;j<n;j++){
            while(ind[j]<m&&used[a[j][ind[j]]])ind[j]++;
        }
    }
    cout<<ans<<"\n";
}