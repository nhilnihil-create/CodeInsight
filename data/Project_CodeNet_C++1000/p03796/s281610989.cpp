#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const long long int m=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ans=(ans%m*i%m)%m;
    }
    cout<<ans<<endl;
    return 0;
}