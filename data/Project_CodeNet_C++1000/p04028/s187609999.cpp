#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=5005,mo=1e9+7;

typedef long long LL;

int n,m,f[N][N];

char S[N];

int main()
{
	scanf("%d%s",&n,S); m=strlen(S);
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		f[i][0]=(f[i-1][0]+f[i-1][1]*2ll)%mo;
		for (int j=1;j<=i;j++) f[i][j]=(f[i-1][j-1]+f[i-1][j+1]*2ll)%mo;
	}
	printf("%d\n",f[n][m]);
	return 0;
}