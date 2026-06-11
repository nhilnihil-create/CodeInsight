#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll ans=(n/11)*2;
    ll rad=n%11;
    if(rad>=1&&rad<=6)
    {
        ans++;
    }
    else if(rad>6&&rad<11)
    {
        ans+=2;
    }
    cout<<ans<<endl;
    return 0;
}