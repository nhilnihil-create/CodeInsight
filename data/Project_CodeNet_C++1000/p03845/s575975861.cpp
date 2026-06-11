#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,m,p,x,sum=0;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    cin>>m;
    while(m--)
    {
        cin>>p>>x;
        ll ans=sum-a[p-1]+x;
        cout<<ans<<endl;

    }

    return 0;
}



