#include<iostream>
#include<cstdio>
#include<cstring>

const int N=510;

int G[N][N];

void solve(int n,int m,int dn)
{
	int B0=(n/dn)*m,A0=n*m-B0;
	int a=A0-B0*(dn-1),K=A0/a+1;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i%dn==0)G[i][j]=-K*(dn-1);
			else G[i][j]=K-1;
}

int n,m,dn,dm;

int main()
{
	scanf("%d%d%d%d",&n,&m,&dn,&dm);
	if(n%dn==0 && m%dm==0)printf("No\n");
	else 
	{
		printf("Yes\n");
		if(n%dn==0)
		{
			solve(m,n,dm);
			int fuck=std::max(n,m);
			for(int i=1;i<=fuck;i++)
				for(int j=1;j<=i;j++)
					std::swap(G[i][j],G[j][i]);
		}
		else solve(n,m,dn);
		
		for(int i=1;i<=n;i++,printf("\n"))
			for(int j=1;j<=m;j++)printf("%d ",G[i][j]);
	}
	return 0;
}
