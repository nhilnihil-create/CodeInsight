#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm=105;
int n,m,A[maxm],jc;
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		A[i]=read();
		if(A[i]&1) jc++;
	}
	if(jc>2){printf("Impossible\n");return 0;}
	for(int i=2;i<m;i++)
	{
		if(A[i]&1)
		{
			if(A[1]&1) swap(A[i],A[m]);
			else swap(A[i],A[1]);
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d%c",A[i],i==m?'\n':' ');
	if(m==1)
	{
		if(n!=1)
			printf("%d\n%d %d\n",2,1,n-1);
		else
			printf("%d\n%d\n",1,1);
	}
	else
	{
		printf("%d\n",m-(A[1]==1));
		for(int i=1;i<=m;i++)
		{
			if(i==1)
			{
				if(A[1]>1)
					printf("%d ",A[1]-1);
			}
			else if(i==m)
				printf("%d\n",A[m]+1);
			else printf("%d ",A[i]);
		}
	}
	return 0;
}