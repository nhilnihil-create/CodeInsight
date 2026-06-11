#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,f[400010],p;
vector<int> x[100010];
inline void add(int i,int j,int k,int l,int r)
{
	if(l<=j && k<=r)
	  f[i]++;
	else
	  {
	   if(l<=(j+k>>1))
	     add(i<<1,j,j+k>>1,l,r);
	   if(r>(j+k>>1))
	     add(i<<1|1,(j+k>>1)+1,k,l,r);
	  }
}
inline int query(int i,int j,int k,int p)
{
	if(j==k)
	  return f[i];
	else
	  if(p<=(j+k>>1))
	    return f[i]+query(i<<1,j,j+k>>1,p);
	  else
	    return f[i]+query(i<<1|1,(j+k>>1)+1,k,p);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
	  {
	   scanf("%d%d",&j,&k);
	   x[k-j+1].push_back(j);
	  }
	for(p=1;p<n;p<<=1);
	for(i=1;i<=n;i++)
	  {
	   for(j=i,k=0;j<=n;j+=i)
	     k+=query(1,1,p,j);
	   printf("%d\n",k+m);
	   for(j=0;j<x[i].size();j++,m--)
	     add(1,1,p,x[i][j],x[i][j]+i-1);
	  }
	return 0;
}
