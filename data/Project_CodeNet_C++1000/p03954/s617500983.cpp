#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,a[20000001];
int check1(int i,int j,int x){return a[i]<=x&&a[j]<=x;}
int check2(int i,int j,int x){return a[i]>x&&a[j]>x;} 
int check(int x)
{
    for(int i=0;i<n-1;i++)
	{
        if(check2(n+i,n+i+1,x)||check2(n-i,n-i-1,x))return 0;
        if(check1(n+i,n+i+1,x)||check1(n-i,n-i-1,x))return 1;
    }
    return check1(1,1,x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;i++)scanf("%d",&a[i]);
	int l=1,r=n*2-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))	r=mid-1,ans=mid;
		else			l=mid+1;
	}
	printf("%d",ans);return 0; 
}