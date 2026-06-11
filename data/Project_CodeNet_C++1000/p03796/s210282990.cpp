#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
    int n;
    cin>>n;
    int m=1e9+7;
     int ans=1;
     for(int i=2;i<=n;i++)
     ans=(ans*i)%m;
     cout<<ans<<endl;
}