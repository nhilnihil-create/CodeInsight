#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=4000000;
const int MOD=1e9+7;
long long a[MAXN+10],pre[MAXN+10],n,k,f[2200][2200];
long long C(long long p,int x){
	return 1ll*(pre[p]*a[x])%MOD*a[p-x]%MOD;
}
long long pp(int x,int p){
	long long ans=1,m=x;
	while(p){
		if(p&1)(ans*=m)%=MOD;
		p>>=1;(m*=m)%=MOD;
	}
	return ans;
}
int main(){
//	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&k);
    if(k==1){
        printf("1");
        return 0;
    }
	pre[0]=1;
	for(int i=1;i<=MAXN;i++)pre[i]=(1ll*i*pre[i-1])%MOD;
	a[MAXN]=pp(pre[MAXN],MOD-2);for(int i=MAXN-1;i>=0;i--)a[i]=a[i+1]*(i+1)%MOD;
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(i)f[i][j]=(f[i-1][j]+f[i][j])%MOD;
			if(j)f[i][j]=(f[i][j]+1ll*f[i][j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2)%MOD)%MOD;
		}
	}
	long long ans=1ll*f[n][n]*pre[n]%MOD;
	printf("%d",ans);
	return 0;
}