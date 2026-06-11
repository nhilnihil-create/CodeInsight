#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005,M=1e9+7;
int n,m,a,b,fac[N],inv[N],dp[N];
int ksm(int x,int y){
	if (!y)return 1;
	int z=ksm(x,y/2);
	z*=z;z%=M;
	if (y&1)z*=x;
	return z%M;
}
int C(int x,int y){
	if (x<y)return 0;
	return fac[x]*inv[y]%M*inv[x-y]%M;
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	n--;m--;
	fac[0]=inv[0]=1;
	for (int i=1;i<N;i++)fac[i]=fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	int sum=0;
	for (int i=b-1;i>=0;i--){
		dp[i]=(C(n+m-i-(n-a+1),n-(n-a+1))-sum+M)%M;
		(sum+=dp[i])%=M;
	}
	int ans=C(n+m,n);
	for (int i=0;i<b;i++)(ans+=M-C(i+(n-a+1),i)*dp[i]%M)%=M;
	printf("%lld\n",ans);
	return 0;
}