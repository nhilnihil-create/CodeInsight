#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) f^=(ch=='-');
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return f ? -x :x ;
}
const int maxn=1e5+20;
int n,a[maxn],pos[maxn],c[maxn],m,k,s[maxn],top,ans[maxn];
bool vis[maxn];
signed main(){
	n=read();
	for (int i=1;i<=n;++i) {
		a[i]=read();
		pos[i]=i;
	}
	for (int i=1;i<=n;++i) c[i]=a[i]-a[i-1];
	m=read();
	k=read();
	for (int i=1,x;i<=m;++i) {
		x=read();
		swap(pos[x],pos[x+1]);
	}
	for (int i=1;i<=n;++i) {
		if (!vis[i]) {
			top=0;
			for (int j=i;!vis[j];j=pos[j]) {
				s[++top]=j;
				vis[j]=1;
			}
			for (int j=1;j<=top;++j) {
				ans[s[j]]=c[s[(k+j-1)%top+1]];
			}
		}
	}
	for (int i=1;i<=n;++i) {
		ans[i]+=ans[i-1];
		printf("%lld",ans[i]);
		putchar('.');
		putchar('0');
		putchar('\n');
	}
 	return 0;
}