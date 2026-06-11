#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct W{int i,x;}w[510];int cnt[510],res[510];
bool cmp(W a,W b){return a.x<b.x;}
int n,p,tot,k;
int cntx[250010];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&w[i].x);
		w[i].i=i;cntx[w[i].x]=i;
	}
	w[0]=W{500010,1};w[n+1]=W{500010,n*n+1};
	sort(w+1,w+n+1,cmp);
	for (int i=1;i<=n;i++) cnt[i]=w[i].i,res[i]=n-cnt[i];
	
	p=w[1].x;
	for (int i=1;i<=n;i++)
	{
		p-=cnt[i];
		if (p<0){printf("No");return 0;}
		p+=w[i+1].x-w[i].x;
	}
	p=w[n+1].x-w[n].x;
	for (int i=n;i;i--)
	{
		p-=res[i]+1;
		if (p<0) {printf("No");return 0;}
		p+=w[i].x-w[i-1].x;
	}
	
	printf("Yes\n");
	tot=1;k=1;
	for (int i=1;i<=n*n;i++)
	{
		if (cntx[i]) 
		{printf("%d ",cntx[i]);continue;}

		while (cnt[tot]<=1) tot++;		
		if (tot<=n) printf("%d ",w[tot].i),cnt[tot]--;
		else
		{
			while (!res[k]) k++;
			printf("%d ",w[k].i);res[k]--;
		}
	}
	
}