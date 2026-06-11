#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef double db;
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
const int N=5e3+5,mo=1e9+7,rt=3;
ll f[N][N],i,j,n,m;
char s[N];
int main()
{
	scanf("%lld %s",&n,s+1);
	m=strlen(s+1);
	f[0][0]=1;
	fo(i,0,n-1)
		fo(j,0,i) 
		{
			(f[i+1][j+1]+=f[i][j])%=mo;
			if (j) 
				(f[i+1][j-1]+=f[i][j]*2)%=mo;
			else (f[i+1][j]+=f[i][j])%=mo;
		}
	printf("%lld\n",f[n][m]);
}