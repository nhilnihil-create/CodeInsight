#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll pw[51];
int b[51],c[51],top,len;
int m,num,mx=50;

void init()
{
	pw[0]=1;
	for(int i=1;i<=50;i++) pw[i]=pw[i-1]<<1;
}

int main()
{
	scanf("%lld",&n);
	init(); 
	while(pw[mx]>n) mx--;
	n-=pw[mx];
	m=mx;
	c[++top]=mx+1,c[++top]=mx+1;
	len=2*m+2;
	num=m+1;
	while(n)
	{
		while(pw[mx]>n) mx--;
		n-=pw[mx];
		c[++top]=++num;
		b[mx]=num;
		len+=2;
	}
	printf("%d\n",len);
	for(int i=0;i<=m;i++)
	{
		if(i) printf("%d ",i);
		if(b[i]) printf("%d ",b[i]);
	}
	for(int i=1;i<=m;i++) printf("%d ",i);
	for(int i=1;i<=top;i++) printf("%d ",c[i]); 
	
	return 0;
}