#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
typedef std::pair<int,int> P;
#define mk std::make_pair
#define fr first
#define sc second
inline int in()
{
	int k=0;char ch=gt;bool p=1;
	while(ch<'-')ch=gt;if(ch=='-')ch=gt,p=0;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return p?k:-k;
}
const int YL=1e9+7,N=1e6+5;
inline void add(int &x,int y){if((x+=y)>=YL)x-=YL;}
int dp[N],sum[N];
int main()
{
	int n=in(),r=1ll*(n-1)*(n-1)%YL;dp[1]=n,dp[2]=1ll*n*n%YL;
	sum[1]=sum[2]=dp[1],add(sum[2],dp[2]);
	for(int i=3;i<=n;++i)
	{
		sum[i]=sum[i-1];
		add(dp[i],dp[i-1]);
		add(dp[i],r);
		add(dp[i],sum[i-3]);
		add(dp[i],n-i+2);
		add(sum[i],dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
