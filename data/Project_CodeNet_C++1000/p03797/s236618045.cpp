#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    ans = min(n,m/2);
    n-=ans;
    m-=2*ans;
    ans+=(m/4);
    cout<<ans;
}