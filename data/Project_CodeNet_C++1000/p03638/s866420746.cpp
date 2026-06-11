#include<bits/stdc++.h>
using namespace std;
int a[101][101],b[10001];
int main ()
{
	int h,w;
	scanf("%d%d",&h,&w);
		int i,j,t,k=0;
		scanf("%d",&t);
		for(i=0;i<t;i++)
			scanf("%d",&b[i]);
		for(i=0;i<h;i++)
		{
			if(i%2==0)
				for(j=0;j<w;j++)
				{
					a[i][j]=k+1;
					b[k]--;
					if(b[k]==0)
						k++;
				}
			if(i%2==1)
				for(j=w-1;j>=0;j--)
				{
					a[i][j]=k+1;
					b[k]--;
					if(b[k]==0)
						k++;
				}
		}
		for(i=0;i<h;i++)
		{
			for(j=0;j<w-1;j++)
				printf("%d ",a[i][j]);
			printf("%d\n",a[i][w-1]);
		}
		return 0;
	}

