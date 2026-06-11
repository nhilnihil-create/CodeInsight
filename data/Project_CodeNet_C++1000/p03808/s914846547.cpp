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
    ll n;
    cin>>n;
    V<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    ll d=n*(n+1)/2;    
    if(sum%d!=0){
        cout<<"NO"<<"\n";
        return 0;
    }
    if(n==1){
        cout<<"YES"<<"\n";
        return 0;
    }
    ll times=sum/d,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]-a[(i+1)%n]>0){
            cnt+=(a[i]-a[(i+1)%n]+n-2)/(n-1);
        }
    }
    if((sum-cnt*d)%(d*n)==0)cout<<"YES"<<"\n";
     else cout<<"NO"<<"\n";

}
