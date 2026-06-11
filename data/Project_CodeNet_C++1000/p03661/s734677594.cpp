#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
const int N=2e5+3;
ll a[N],d[N],d1[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j,n,l;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    d[0]=a[0];
    for(i=1;i<n;i++)
    {
        d[i]=a[i]+d[i-1];
    }
    d1[n-1]=a[n-1];
    for(i=n-2;i>=0;i--)
    {
        d1[i]=a[i]+d1[i+1];
    }
    ll mn=2e18;
    for(i=0;i<(n-1);i++)
    {
        mn=min(mn,(abs(d[i]-d1[i+1])));
    }
    cout<<mn<<"\n";
    return 0;
}