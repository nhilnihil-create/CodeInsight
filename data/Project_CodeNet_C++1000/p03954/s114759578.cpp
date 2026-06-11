#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const int maxm=2e5+7;
typedef long long ll;
int n,l,r,ans;
int a[2*maxm];
bool check(int k)
{
  for(int i=0;i<n-1;i++)
  {
     if((a[n+i]>=k&&a[n+i+1]>=k)||(a[n-i]>=k&&a[n-i-1]>=k)) return 1;
     if((a[n+i]<k&&a[n+i+1]<k)||(a[n-i]<k&&a[n-i-1]<k)) return 0;
  }
  return a[1]>=k;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=2*n-1;i++)
 {
    scanf("%d",&a[i]);	
 }
 l=1,r=2*n-1;
 while(l<=r)
 {
    int mid=(l+r)>>1;
	if(check(mid))
	{
	   ans=mid;
	   l=mid+1;	
	}
	else r=mid-1;
 }
 printf("%d\n",ans);
 return 0;	
}