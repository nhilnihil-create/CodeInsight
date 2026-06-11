#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
    int n,c,b;
    cin>>n>>c>>b;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int ans=0;
    for(int i=1;i<n;i++)
    {
        int check=(a[i]-a[i-1])*c;
        if(check>b)ans+=b;
        else
        ans+=check;
    }
    cout<<ans<<endl;
}