#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define maxn 100005
#define LL long long
using namespace std;

template<class T>inline void read(T &res)
{
	char ch;
	for(;!isdigit(ch=getchar()););
	for(res= ch-'0';isdigit(ch=getchar());res=res*10+ch-'0');
}
int n;
LL dp[maxn][3],val[maxn];
char op;

int main()
{
	scanf("%d",&n);
	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = -0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		read(val[i]);
		if(i<n) while((op = getchar())!='-'  && op!='+');
		dp[i][0] = max(dp[i-1][0] + val[i] , max(dp[i-1][1] - val[i] , dp[i-1][2] + val[i]));
		dp[i][1] = max(dp[i-1][1] - val[i] , dp[i-1][2] + val[i]);
		dp[i][2] = dp[i-1][2] + val[i];
		if(op=='-')
		{
			for(int j=2;j>0;j--) dp[i][j] = dp[i][j-1];
			dp[i][0] = -0x3f3f3f3f3f3f3f3f;
		}
	}
	printf("%lld\n",max(dp[n][0] ,max( dp[n][1] , dp[n][2])));
}
