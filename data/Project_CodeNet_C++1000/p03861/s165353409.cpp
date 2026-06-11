#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=b/c;
    if(a-1>=0)
    {
        ans-=(a-1)/c;
    }
    else
    {
        ans++;
    }
    cout<<ans;
  	return 0;
}





