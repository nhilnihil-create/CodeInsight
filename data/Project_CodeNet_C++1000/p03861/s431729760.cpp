#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,x,ans;
    cin>>a>>b>>x;
    if(a%x==0)
        ans=b/x-a/x+1;
    else
        ans=b/x-a/x;
    cout<<ans<<endl;
}
