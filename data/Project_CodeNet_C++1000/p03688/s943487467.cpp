#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

ll a[110000];
int main(){
    ll n,m,ans=0;
    cin>>n;
    bool f=true;
    rep(i,0,n)cin>>a[i];
    sort(a,a+n);
    rep(i,0,n)if(a[i]==a[0])ans++;
    ll y=a[n-1]-a[0];
    if(y>1)cout<<"No"<<endl;
    if(y==0){
        if(n==a[0]+1||n>=a[0]*2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    if(y==1){
        if(ans==a[0])cout<<"Yes"<<endl;
        else if((n-ans)/2+ans==a[n-1]&&(n-ans)%2==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
}
