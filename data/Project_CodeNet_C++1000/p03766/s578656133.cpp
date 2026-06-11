#include<cstdio>
#define ll long long
const int N=1e6+5,mo=1e9+7;
int n,i,s,f[N];
int main(){
	scanf("%d",&n);int v=(ll)(n-1)*(n-1)%mo;
	f[0]=1;f[1]=n;f[2]=(ll)n*n%mo;
	for (i=3;i<=n;i++) s=(s+f[i-3])%mo,
		f[i]=((ll)f[i-1]+s+v+(n-i+1))%mo;
	printf("%d",f[n]);
}