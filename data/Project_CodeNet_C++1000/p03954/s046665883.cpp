#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const int maxm=1e5+7;
typedef long long ll;
int n,l,r,ans;
int a[2*maxm];
bool big(int i,int j,int k)
{
   if(a[i]>=k&&a[j]>=k)
   return 1;
   else return 0;	
}
bool small(int i,int j,int k)
{
   if(a[i]<k&&a[j]<k)
   return 1;
   else return 0;	
}
bool check(int x)
{
  for(int i=0;i<n-1;i++)
  {
     if(big(n+i,n+i+1,x)||big(n-i,n-i-1,x)) return 1;
     if(small(n+i,n+i+1,x)||small(n-i,n-i-1,x)) return 0;
  }
  return big(1,1,x);
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