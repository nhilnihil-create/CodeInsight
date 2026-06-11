#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define mod 1000000007
typedef long long LL;
int n,m;
LL f[5005][5005];
char s[5005];
int main()
{
	scanf("%d",&m);
	scanf("%s",s);
	n=strlen(s);
	f[0][0]=1;
	for(int j=1;j<=m;j++)
		for(int i=0;i<=m;i++)
		{
			if(i!=m)
				f[i][j]+=2ll*f[i+1][j-1];
			if(i==0)
				f[i][j]+=f[i][j-1];
			else
				f[i][j]+=f[i-1][j-1];
			f[i][j]%=mod;
		}
	printf("%lld",f[n][m]);
}