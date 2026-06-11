#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,a,b,x,ans=0;
    cin>>a>>b>>x;
    ans=(b/x)-(a/x);
    if(a%x==0) ans++;
    cout<<ans<<endl;

    return 0;
}



