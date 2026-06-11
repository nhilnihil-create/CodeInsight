#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod= 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    ll ans = 1;
    for(int i=1;i<=n;++i){
        ans = (ans*i)%mod;
    }    
    cout<<ans;
}