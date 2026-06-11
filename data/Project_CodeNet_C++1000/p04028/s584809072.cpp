#include<cstdio>
#include<cstring>
const int mod=1e9+7;
#define max(a,b) (a>b?a:b)
int matmod(long long v,long long k){
	long long ans=1ll;
	for(;k;k>>=1){
		if(k&1) ans=(ans*v)%mod;
		v=(v*v)%mod;
	}
	return (int) ans;
}
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char num[5005];
int f[5005][5005],n;
int main(){
	n=read();
	scanf("%s",num);
	int len=strlen(num);
	int pu=1;
	for(int i=1;i<=len;i++) pu=(pu*2)%mod;
	pu=matmod(pu*1ll,mod-2);
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++){
			f[i+1][j+1]=(f[i+1][j+1]+2*f[i][j]%mod)%mod;
			f[i+1][max(j-1,0)]=(f[i+1][max(j-1,0)]+f[i][j])%mod;
		}
	long long ans=((long long) pu)*((long long) f[n][len])%mod;
	printf("%lld",ans);
	return 0;
}