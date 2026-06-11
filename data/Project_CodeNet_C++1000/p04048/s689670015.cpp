#include<bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
typedef long long int ll;
typedef string S;
#define M 1e18
#define AS 250005
#define in(x)  cin>>x
#define o(x)  cout<<x
#define sp cout<<' '
#define nw cout<<endl
#define rt return
#define fr(i,a,n) for(ll i=a;i<=n;i++)
#define frm(i,a,n) for(ll i=n;i>=a;i--)
#define P pair<ll,ll>
#define vc vector<ll>
#define pb push_back
#define MP map<ll,ll>
bool sortin(const pair<ll,ll> &e,const pair<ll,ll> &f){return (e.first<f.first);}
bool POT(ll x){return x && (!(x&(x-1)));}
ll i,j,k,l,m,n,p,q,r,a,b,c,x,y,z,ts,mn=1e18,mod=1e9+7;
ll ar[AS],br[AS],xr[AS];
int main()
{
    fast;
    in(n>>x);
    n-=__gcd(n,x);
    o(n*3);
}
