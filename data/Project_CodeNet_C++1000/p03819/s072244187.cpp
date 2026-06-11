#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct qq{int l,r;}a[300005];
int m,n,now,b[100005];
bool cmp(qq e,qq f)
{
	return e.r-e.l<f.r-f.l;
}
void add(int x,int d)
{
	for (int k=x;k<=n;k+=k&-k)
	  b[k]+=d;
}
int sum(int x)
{
    int s=0;
	for (int k=x;k;k-=k&-k)
	  s+=b[k];
	return s;  
}
int main()
{
   scanf("%d%d",&m,&n); 
   for (int i=1;i<=m;i++)
     scanf("%d%d",&a[i].l,&a[i].r);
   sort(a+1,a+1+m,cmp); 
   now=1;
   for (int i=1;i<=n;i++)
     {
     int ans=0;	
	 for (int j=now;j<=m;j++)
	   if (a[j].r-a[j].l<i) 
	   {
	   add(a[j].l,1);
	   add(a[j].r+1,-1); 
	   now++;
       }
       else
       break;
     for (int j=i;j<=n;j+=i)
	   ans+=sum(j);
	 printf("%d\n",(m-now+1)+ans);
     }
}