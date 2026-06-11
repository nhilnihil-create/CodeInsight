#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
int n,k,i,j,dp[2005][2005],mod=1e9+7,fac[4000005],inv[4000005],fi[4000005];
int c(int x,int y)
{
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
int main()
{
	fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;
	fz(i,2,4000000){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod;
	}
	scanf("%d%d",&n,&k);
	if(k==1){
		puts("1");
		return 0;
	}
	dp[0][0]=1;
	fz1(i,n)fz0g(j,i){
		dp[i][j]=0;
		inc(dp[i][j],dp[i-1][j])
		if(j)inc(dp[i][j],1ll*dp[i][j-1]*(n-j+1)%mod*c(n-i+(n-j+1)*(k-1)-1,k-2)%mod)
	}
	cout<<dp[n][n]<<endl;
	return 0;
}