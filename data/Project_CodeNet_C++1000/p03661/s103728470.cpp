#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[200009];
ll a[200009];
int main()
{
    int n;
    cin>>n;
    ll t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];

    }
    ll minn=1e15;
    for(int i=1;i<=n-1;i++)
    {
        minn=min(minn,abs(sum[i]-(sum[n]-sum[i])));
    }
    cout<<minn<<endl;
}
