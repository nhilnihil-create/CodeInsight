//Reconciled?

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,m;cin>>n>>m;
    if(abs(n-m)>1){
        cout<<0<<nnn;
        return 0;
    }
    int ans = 1;
    rep(i,1,n+1)ans=(ans*i)%1000000007;
    rep(i,1,m+1)ans=(ans*i)%1000000007;
    if((n+m)%2==0)ans=(ans*2)%1000000007;
    cout<<ans<<nnn;
    return 0;
}