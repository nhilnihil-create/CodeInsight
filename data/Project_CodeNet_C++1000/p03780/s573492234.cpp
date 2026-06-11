#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=5005;
int n,k;
int a[maxn];
bool dp[maxn][maxn];
bool check(int mid)
{
    if(a[mid]>k)
    return 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(!dp[i][j])
            continue;
            if(i!=mid)
            {
                int next=min(a[i]+j,k);
                dp[i+1][next]=1;
            }
            dp[i+1][j]=1;
        }
    }
    for(int i=k-a[mid];i<k;i++)
    {
        if(dp[n][i])
        return 1;
    }
    return 0;
}
int main()
{ 
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
	}
    sort(a,a+n);
    int l=-1,r=n,mid;
    while(l+1<r)
    {
        mid=(l+r)/2;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        if(check(mid))
        r=mid;
        else
        l=mid;
    }
    cout<<l+1;
    return 0;
}