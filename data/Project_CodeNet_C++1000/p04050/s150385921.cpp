#include<iostream>
#include<cstdio>
#include<cstring>
const int N=105;
int s[N];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",s+i);
		if(s[i]&1)cnt++;
	}
	if(cnt>2)printf("Impossible\n");
	else 
	{
//		if(cnt==1)while(1){printf("caonidaoye\n");}

		if(m==1)
		{
			if(s[1]>1)printf("%d\n2\n%d %d\n",s[1],1,s[1]-1);
			else printf("1\n1\n1\n");
		}
		else 
		{
			for(int i=1;i<=m;i++)if(s[i]&1){std::swap(s[1],s[i]);break;}
			for(int i=2;i<=m;i++)if(s[i]&1){std::swap(s[m],s[i]);break;}

			for(int i=1;i<=m;i++)printf("%d ",s[i]);printf("\n");

			printf("%d\n",m-(s[m]==1));
			printf("%d ",s[1]+1);
			for(int i=2;i<m;i++)printf("%d ",s[i]);
			if(s[m]>1)printf("%d\n",s[m]-1);
		}
	}
	return 0;
}
