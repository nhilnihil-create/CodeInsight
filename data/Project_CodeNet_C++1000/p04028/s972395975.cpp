#include<cstdio>
#include<cstring>
#define clz 1000000007
#define ll long long
char s[5010];
int f[5010][5010];
int n;
long long ans;
int Max(int p,int q){
	return p>q?p:q;
}
ll qsm(ll x,int k){
	ll ans=1ll;
	while(k){
		if(k&1) ans=ans*x%clz;
		x=x*x%clz;
		k>>=1;
	}
	return ans;
}
int main(){
	//freopen("keyboard.in","r",stdin);
	//freopen("keyboard.out","w",stdout);
	scanf("%d%s",&n,s);
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i+1][j+1]+=f[i][j]*2;
			f[i+1][j+1]%=clz;
			f[i+1][Max(j-1,0)]+=f[i][j];
			f[i+1][Max(j-1,0)]%=clz;
		}
	}
	int m=strlen(s);
		ans+=1ll*qsm(qsm(2,m),clz-2)*f[n][m]%clz;
		ans%=clz;
	printf("%lld",ans);
	return 0;
}