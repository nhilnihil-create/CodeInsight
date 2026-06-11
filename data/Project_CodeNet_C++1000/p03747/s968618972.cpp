#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long 
const int maxn = 1e5+10;
const ll INF = 1e13;
int n,l,t;
int a[maxn];
int b[maxn];
int c[maxn];
ll m;
int wk(int x,int y)
{
	if(x>=y) 
	{
		x-=y;
		return x;
	}
	y-=x+1; m--;
	int tmp=y/l;
	m-=(ll)tmp;
	y-=tmp*l;
	return l-1-y;
}
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			c[i-1]=(a[i]+t)%l;
			m+=(ll)((a[i]+t)/l);
		}
		else
			c[i-1]=wk(a[i],t);
	}
	sort(c,c+n);
	m=(m+(ll)n*(ll)INF)%(ll)n;
	int tmp=(int)m;
	for(int i=0;i<n;i++) printf("%d\n",c[(i+m)%n]);
	return 0;
}