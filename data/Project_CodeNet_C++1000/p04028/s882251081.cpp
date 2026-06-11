#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 5005
#define mod 1000000007
long long n,len,f[MN][MN],jie;
char s[MN];
int main(){
	n=read();
	scanf("%s",s+1);
	len=strlen(s+1);
	f[0][0]=1;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++){
		f[i+1][j+1]=(f[i][j]*2+f[i+1][j+1])%mod;
		f[i+1][j==0?j:j-1]=(f[i][j]+f[i+1][j==0?j:j-1])%mod;
	}
	jie=1;for(int i=1;i<=len;i++) jie<<=1,jie>mod?jie-=mod:0;
	long long m=mod-2,res=1,ans=0;
	while(m){
		if(m&1) res=(res*jie)%mod;
		m>>=1;jie=(jie*jie)%mod;
	}
//	for(int i=0;i<=n;i++) ans+=f[i][len];
//	printf("%d\n",ans);
	printf("%lld\n",(f[n][len]*res)%mod);
	return 0;
}