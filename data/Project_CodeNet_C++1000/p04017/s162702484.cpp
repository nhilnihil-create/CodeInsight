#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5;
int dep[N],f[20][N],fst[N],to[N],n,L,q,x[N],mm,sum[N];
int query(int l,int r)
{
	int ans=0;
	for(int i=17;i>=0;i--)if(f[i][l]&&f[i][l]<r)ans+=1<<i,l=f[i][l];
	return ans+(l!=r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",x+i);
	scanf("%d%d",&L,&q);long long s=0;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+x[i]-x[i-1];
	for(int i=1,j=2;i<n;i++)
	{
		while(s+x[j]-x[j-1]<=L&&j<=n)s+=x[j]-x[j-1],++j;
		f[0][i]=j-1;
		s-=x[i+1]-x[i];
	}
	for(int i=1;i<=17;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=f[i-1][f[i-1][j]];
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);if(l>r)swap(l,r);
		printf("%d\n",query(l,r));
	}
}