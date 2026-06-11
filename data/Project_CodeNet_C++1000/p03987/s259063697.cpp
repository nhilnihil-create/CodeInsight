#include<cstdio>
using namespace std;
const int maxn=200005;
int n,a[maxn],L[maxn],R[maxn];
long long ans;
inline int read(){
	int ret=0;bool f=0;char ch=getchar();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return f?-ret:ret;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	for (L[i]=i-1;a[L[i]]>a[i];L[i]=L[L[i]]);
	for (int i=n;i;i--)
	for (R[i]=i+1;a[R[i]]>a[i];R[i]=R[R[i]]);
	for (int i=1;i<=n;i++)
	ans+=1ll*a[i]*(i-L[i])*(R[i]-i);
	printf("%lld\n",ans);
	return 0;
}