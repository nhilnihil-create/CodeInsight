#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int x,y;
    cin>>x>>y;
    if(k>=n)
    {
        cout<<n*x<<endl;
    }
    else
    {
        int ans=k*x;
        n=n-k;
        ans+=n*y;
        cout<<ans<<endl;
    }
}