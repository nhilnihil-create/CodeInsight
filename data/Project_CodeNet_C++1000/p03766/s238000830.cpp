#include<bits/stdc++.h>
using namespace std;
#define N 1111116
#define mod 1000000007

int n,f[N],cnt;

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	int n=read();
	f[1]=n;f[2]=1ll*n*n%mod;cnt=(f[1]+f[2])%mod;
	for (int i=3;i<=n;i++)
		f[i]=(1ll*(n-1)*(n-1)+(n-i+2)+cnt-f[i-2]+mod)%mod,
		cnt=(cnt+f[i])%mod;
	printf("%d\n",f[n]);
	return 0;
}