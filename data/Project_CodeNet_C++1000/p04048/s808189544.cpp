#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);ios::sync_with_stdio(false);

ll f(ll a,ll b){
    if(b==0)return a;

    ll res=((a-1)/b)*2*b;
    

    res+=f(b,a%b);

    return res;
}

signed main(){
    ll n,x,ans=0;cin>>n>>x;
    ans+=n+f(max(x,n-x),min(x,n-x));

    cout<<ans<<endl;
}
