#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int mod=1e9+7;
const int maxn=1e6+20;

int n,dp[maxn],s[maxn],s1[maxn];
int ans;

inline void init()
{
	n=read();
	dp[1]=1; s[1]=s1[1]=1;
	REP(i,2,n)
	{
		dp[i]=1;
		if(i-3>=1)dp[i]=(dp[i]+(ll)(i-2)*s[i-3]-s1[i-3]+mod)%mod;
		s[i]=(s[i-1]+dp[i])%mod; s1[i]=(s1[i-1]+(ll)i*dp[i])%mod;
	}
	ans=(ans+1)%mod;
	REP(i,1,n-1)ans=(ans+(ll)dp[i]*(n-1)%mod*(n-1))%mod;
	REP(i,1,n)ans=(ans+(ll)dp[i]*(n-1))%mod;
	printf("%d\n",ans);
}

int main()
{
	init();
	return 0;
}

