#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int num[500005];
int vis[500005];
int t;

int abs1(int x)
{
   if (x>=0)
      return x;
   else
      return -x;
}
int check(int x)
{
   x%=2;
   if (x==0)
      return (vis[t]^1);
   else
      return vis[t];
}

int main()
{
cin>>t;
for (int a=1;a<=2*t-1;a++)
   scanf("%d",&num[a]);
int l=1,r=2*t-1;
int mid;
int k;
while (l<=r)
{
   mid=(l+r)>>1;
   k=-1;
   for (int a=1;a<=2*t-1;a++)
      if (num[a]>=mid)
         vis[a]=1;
      else
         vis[a]=0;
   pair<int,int> flag1;
   pair<int,int> flag2;
   flag1.first=-1;
   flag2.first=-1;
   for (int a=t;a>=2;a--)
      if (vis[a]==vis[a-1])
      {
	     flag1.second=vis[a];
         flag1.first=a;
         break;
	  }
   for (int a=t;a<2*t-1;a++)
      if (vis[a]==vis[a+1])
      {
         flag2.second=vis[a];
         flag2.first=a;
         break;
	  }
   if (flag1.first!=-1||flag2.first!=-1)
   {
      if (abs1(flag1.first-t)>abs1(flag2.first-t))
         k=flag2.second;
      else
         k=flag1.second;
   }
   if (k==-1)
      k=check(t);
   if (k==0)
      r=mid-1;
   if (k==1)
      l=mid+1;
}
cout<<r;
	return 0;
}