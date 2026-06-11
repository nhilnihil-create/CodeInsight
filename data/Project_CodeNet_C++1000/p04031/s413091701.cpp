#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    int minm=500,maxm=-500;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxm=max(maxm,a[i]);
        minm=min(minm,a[i]);
    }
    int ans=1e8,cost=0;
    for(int i=minm;i<=maxm;i++)
    {
        for(int j=0;j<n;j++)
        {
            int y=abs(i-a[j]);
            cost+=y*y;
        }
        ans=min(ans,cost);
        cost=0;
    }
    cout<<ans;
    return 0;
}





