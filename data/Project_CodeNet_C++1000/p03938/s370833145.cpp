#include<cstdio>
using namespace std;
const int maxn=20005;
int n,ans[2][maxn];
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int ret=0;bool f=0;char ch=nc();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=nc();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=nc();
	return f?-ret:ret;
}
int main(){
	n=read();
	ans[0][0]=1,ans[1][n+1]=1;
	for (int i=1;i<=n;i++){
		int x=read();
		ans[0][x+1]+=n-i+1,ans[1][x-1]+=n-i+1;
	}
	for (int i=1;i<=n;i++) ans[0][i]+=ans[0][i-1];
	for (int i=n;i;i--) ans[1][i]+=ans[1][i+1];
	for (int i=1;i<=n;i++) printf("%d%c",ans[0][i],i==n?'\n':' ');
	for (int i=1;i<=n;i++) printf("%d%c",ans[1][i],i==n?'\n':' ');
	return 0;
}