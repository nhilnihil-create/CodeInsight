#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ll n,m,ans=1,mod=1e9+7;
    cin>>n>>m;

    if(abs(n-m)>1){
        cout<<0<<endl;
    }else if(abs(n-m)<=1){
        for(int i=1;i<=n;i++){
            ans=(ans*i)%mod;
        }
        for(int i=1;i<=m;i++){
            ans=(ans*i)%mod;
        }

        if(n==m) ans=(ans*2)%mod;

        cout<<ans<<endl;
    }
    
}
