//Biscuits

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define nxvarep(n,x,a) ll n,x;cin>>n>>x;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
#define cout15(a) printf("%.15f\n",a)
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<ll,string> p;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int main (){
    nxvarep(n,p,a);
    int guu=0,ki=0;
    ll ans=1;
    rep(i,0,n){
        if(a[i]%2==0)guu++;
        else ki++;
    }
    if(ki==0)if(p==1){cout<<0<<nnn;return 0;}
    rep(i,0,guu)ans*=2;
    rep(i,0,ki-1)ans*=2;
    cout<<ans<<nnn;
    return 0;
}