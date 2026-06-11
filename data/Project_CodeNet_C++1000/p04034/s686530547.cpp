//

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
using p = pair<ll, bool>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,m;cin>>n>>m;
    vector<p>h(n);
    rep(i,0,n){
        h[i].first=1;
        h[i].second=false;
    }
    h[0].second=true;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        a--;b--;
        h[a].first--;
        h[b].first++;
        if(h[a].second)h[b].second=true;
        if(h[a].first==0)h[a].second=false;
    }
    int ans = 0;
    rep(i,0,n)if(h[i].second)ans++;
    cout<<ans<<nnn;
    return 0;
}