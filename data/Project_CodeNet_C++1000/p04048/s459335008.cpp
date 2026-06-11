#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    ll n,x;
    cin>>n>>x;
    ll a=max(n-x,x),b=min(n-x,x);
    ll ans=n;
    while(b)
    {
        ll q=a/b;
        ll r=a%b;
        ans+=(b*2)*q;
        if(r==0)ans-=b;

        a=b,b=r;
    }
    cout<<ans<<endl;
}
