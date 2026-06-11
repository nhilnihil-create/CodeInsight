#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    int minimum;
    minimum=min(n,k);
    int ans;
    ans=minimum*x;
    n-=minimum;
    ans+=n*y;
    cout<<ans<<endl;
    return 0;
}
