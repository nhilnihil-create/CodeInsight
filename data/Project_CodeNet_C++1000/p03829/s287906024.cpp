#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1000000007;
const double PI = 3.141592653589793238463;
const ll N=2e5+9;
int main()
{
    FASTINOUT;
    ll x,a,b;
    cin>>x>>a>>b;
    ll y[x];
    for (int i=0;i<x;i++)
        cin>>y[i];
    ll ans=0;
    for (int i=1;i<x;i++){
        ans+=min((y[i]-y[i-1])*a,b);
    }
    cout<<ans<<endl;
    return 0;
}
