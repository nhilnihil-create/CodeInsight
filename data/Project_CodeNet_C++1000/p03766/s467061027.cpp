#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100,mod=1000000007;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,f[maxn],s[maxn],ans;
int main(){
	n=read();
	f[0]=s[0]=1;
	FOR(i,1,n){
		f[i]=f[i-1];
		if(i>=3) f[i]=(f[i]+s[i-3])%mod;
		s[i]=(s[i-1]+f[i])%mod;
	}
	FOR(i,0,n-2) ans=(ans+1ll*(i+1+1ll*(n-1)*(n-1))%mod*f[i])%mod;
	ans=(ans+1ll*(n-1)*f[n-1])%mod;
	printf("%d\n",(f[n]+ans)%mod);
}