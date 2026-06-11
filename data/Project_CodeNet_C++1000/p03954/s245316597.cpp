#include<bits/stdc++.h>
using namespace std;
int n,a[20000010];
bool s(int i,int j,int k)
{
    return a[i]<=k&&a[j]<=k;
}
bool b(int i,int j,int k)
{
    return a[i]>k&&a[j]>k;
}
bool check(int k)
{
    for(int i=0;i<n-1;i++)
	{
        if(b(n+i,n+i+1,k)||b(n-i,n-i-1,k))
			return 0;
        if(s(n+i,n+i+1,k)||s(n-i,n-i-1,k))
			return 1;
    }
    return s(1,1,k);
}
int main()
{
    scanf("%d",&n);
    int nn=2*n-1,l=1,r=nn;
    for(int i=1;i<=nn;i++)
        scanf("%d",&a[i]);
    while(l<r)
	{
        int mid=l+(r-l)/2;
        if(check(mid))
            r=mid;
        else
			l=mid+1;
    }
    printf("%d\n",r);
    return 0; 
}