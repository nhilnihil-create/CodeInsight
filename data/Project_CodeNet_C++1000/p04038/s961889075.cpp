#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 2000*2000+5;
const int mod  = 1e9+7;
inline void add(int &a,const int &b){a+=b;if(a>=mod)a-=mod;}

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}
int inv(int x){ return pw(x,mod-2); }

int s[maxn],invs[maxn];
void pre()
{
	s[0]=1; for(int i=1;i<maxn;i++) s[i]=(ll)s[i-1]*i%mod;
	invs[maxn-1]=inv(s[maxn-1]);
	for(int i=maxn-2;i>=0;i--) invs[i]=(ll)invs[i+1]*(i+1)%mod;
}
int C(int n,int m){return (ll)s[n]*invs[m]%mod*invs[n-m]%mod;}

int n,m;
int f[2005];

int main()
{
	pre();
	
	scanf("%d%d",&n,&m); int u=n*m;
	if(m==1) return puts("1"),0;
	
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			add(f[j+1],(ll)f[j]*C(u-i-j*(m-1)-1,m-2)%mod);
	}
	int ans=f[n];
	ans=(ll)ans*s[n]%mod;
	printf("%d\n",ans);
	
	return 0;
}
