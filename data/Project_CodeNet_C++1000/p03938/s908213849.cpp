#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,i,j,temp;
    cin>>n;
    long long p[n+1],a[n+1],b[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(i=1,j=n;i<=n;i++,j--)
    {
        a[i]=i;
        b[i]=j;
    }
    for(i=1;i<=n;i++)
    {
        a[p[i]]=a[p[i]]+i;
        for(j=p[i];j<=n;j++)
        {
            a[j]=a[j]+n;
            b[j]=b[j]-n;
        }
    }
    temp=1-b[n];
    for(i=1;i<=n;i++)
    {
        a[i]=a[i]+temp;
        b[i]=b[i]+temp;
    }
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}