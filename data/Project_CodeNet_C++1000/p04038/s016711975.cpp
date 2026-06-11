#include<cstdio>
#include<cstring>
#include<algorithm>
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
inline int in()
{
	int k=0;char ch=gt;
	while(ch<'-')ch=gt;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return k;
}
const int YL=1e9+7;
inline int MO(const int &a){return a>=YL?a-YL:a;}
inline int ksm(int a,int k){int r=1;while(k){if(k&1)r=1ll*r*a%YL;a=1ll*a*a%YL;k>>=1;}return r;}
int dp[2005][2005],fac[4000005],fnv[4000005];
inline int C(int x,int y){if(x<y||y<0)return 0;return 1ll*fac[x]*fnv[y]%YL*fnv[x-y]%YL;}
int main()
{
	int n=in(),k=in();fac[0]=fnv[0]=1;if(k==1)return puts("1"),0;
	for(int i=1;i<=n*k;++i)fac[i]=1ll*fac[i-1]*i%YL;
	fnv[n*k]=ksm(fac[n*k],YL-2);
	for(int i=n*k-1;i ;--i)fnv[i]=1ll*fnv[i+1]*(i+1)%YL;
	for(int i=1;i<=n&&(dp[i][0]=1);++i)
		for(int j=1;j<=i;++j)
		{
			dp[i][j]=MO(dp[i-1][j]+1ll*C(n-i-1+(n-j+1)*(k-1),k-2)*dp[i][j-1]%YL*(n-j+1)%YL);
		}
	printf("%d\n",dp[n][n]);
	return 0;
}
