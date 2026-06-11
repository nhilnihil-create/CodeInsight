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
    ll x;
    cin>>x;
    ll ans=x/11*2;
    x%=11;
    if (x>6)
        ans+=2;
    else if (x)
        ans++;
    cout<<ans<<endl;
    return 0;
}
