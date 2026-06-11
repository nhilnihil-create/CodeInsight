#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll a,b,c,ans; cin>>a>>b>>c;
    if(a%2==0 || b%2==0 || c%2==0) ans=0;
    else{
        ans = min({a*b, b*c, c*a});
    }
    cout<<ans<<endl;
    return 0;
}