#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int ans=0;
    int k,s;
    cin>>k>>s;
    int x,y,z;
    for(x=0;x<=k;x++)
    {
        for( y=0;y<=k;y++)
        {
        z=s-x-y;
        if(z>=0 && z<=k)
        ans++;
        }
    }
    cout<<ans<<endl;
}