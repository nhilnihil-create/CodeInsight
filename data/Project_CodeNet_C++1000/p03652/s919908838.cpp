#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
int n,m;
cin>>n>>m;
V<V<ll>> a(n,V<ll>(m));
V<bool> use(m,true);
for(int i=0;i<n;i++)for(int j=0;j<m;j++){
cin>>a[i][j];
a[i][j]--;
}
int ans=INT_MAX;
for(int i=0;i<m;i++){
    V<int> cnt(m,0);V<bool> ch(n,false);
    for(int j=0;j<m;j++){
        for(int k=0;k<n;k++){
            if(!use[a[k][j]])continue;
            if(ch[k])continue;
            ch[k]=true;
            cnt[a[k][j]]++;
        }
    }
    ll sum=0;
    for(int j=0;j<m;j++)sum+=cnt[j];
    if(sum<n)break;
    int imax,ma=0;
    for(int j=0;j<m;j++){
        if(chmax(ma,cnt[j]))imax=j;
    }
    use[imax]=false;
    chmin(ans,ma);
}
cout<<ans<<endl;
}