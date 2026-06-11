#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
char p[N];
int S[N],P[N],n;
int main()
{
	scanf("%d",&n);
	scanf("%s",p);
	int i,j;
	for(i=0;p[i];i++)
	{
		if(p[i]=='o') P[i+1]=0;
		else P[i+1]=1;
	}
	P[n+1]=P[1];
	for(i=0;i<8;i++)
	{
		S[0]=i&1;
		S[1]=(i>>1)&1;
		S[2]=(i>>2)&1;
		for(j=2;j<=n+1;j++)
		{
			S[j+1]=S[j-2]^P[j];
		}
		if(S[0]^S[n]^S[1]^S[n+1] || S[1]^S[n+1]^S[2]^S[n+2]) continue;
		for(j=1;j<=n;j++)
		{
			printf("%c",(S[j]^S[j-1])?'W':'S');
		}
		return 0;
	}
	printf("-1\n");
	return 0;
}