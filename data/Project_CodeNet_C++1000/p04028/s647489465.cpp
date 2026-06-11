#include<bits/stdc++.h>
#define int long long
const int mo=1e9+7;
int ksm(int a,int b){
	int ans=1;
	while (b){
		if (b&1) ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return ans;
} 

int n,m,f[5010][5010];
char s[10010];
signed main(){
	scanf("%lld\n",&n);
	scanf("%s",&s);
	m=strlen(s);
	f[0][0]=1;
	for (int i=1;i<=n;++i){
		f[i][0]=(f[i-1][0]+f[i-1][1])%mo;
		for (int j=1;j<=n;++j){
			(f[i][j]+=f[i-1][j-1]*2)%=mo;
			(f[i][j]+=f[i-1][j+1])%=mo;
		} 
	}
		
	printf("%lld\n",f[n][m]*ksm(ksm(2,m),mo-2)%mo);
}