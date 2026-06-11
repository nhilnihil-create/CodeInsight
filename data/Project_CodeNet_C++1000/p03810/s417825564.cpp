#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#define N 110000
using namespace std;
int n,a[N],ans;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int dfs()
{
	int t=0;
	for(int i=1;i<=n;i++) if(a[i]%2==0) t++;
	if(t%2) return 1;
	if(t!=n-1) return 0;
	int g=0;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]%2) {if(a[i]==1) return 0;a[i]--;}
		g=gcd(g,a[i]);
	}
	for(int i=1;i<=n;i++) a[i]/=g;
	return dfs()^1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=dfs();
	if(ans==1) printf("First\n");
	else printf("Second\n");
	return 0;
}