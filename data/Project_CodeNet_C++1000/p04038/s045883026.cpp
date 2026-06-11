#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {char ch = getchar(); ll x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();} return x * f;}
int fastmi(int i,int b,int p){ll ans=1,now=i;while (b)	{if (b&1)  ans=now*ans%p;now=now*now%p;b>>=1;}return ans;}
const int kcz=1e9+7;
const int N=2005;
const int M=4e6+7;
ll f[N][N],mi[M],inv[M],jv[M];
ll C(int n,int m){
	return mi[m]*jv[n]%kcz*jv[m-n]%kcz;}
int main(){
	int n=read(),k=read();
	if (k==1) {printf("1");return 0;}
	
	mi[0]=1;
	inv[0]=1;
	inv[1]=1;
	jv[1]=jv[0]=1;
	for (int i=1;i<=n*k;i++) mi[i]=mi[i-1]*i%kcz;
	for (int i=2;i<=n*k;i++) inv[i]=inv[kcz%i]*(kcz-kcz/i)%kcz;
	for (int i=2;i<=n*k;i++) jv[i]=jv[i-1]*inv[i]%kcz;
	
	
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			f[i][j]=(f[i][j]+f[i-1][j])%kcz;
			if (j)
				f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%kcz*C(k-2,n-i+(n-j+1)*(k-1)-1))%kcz;
		}
	}
	printf("%lld",f[n][n]);
}
