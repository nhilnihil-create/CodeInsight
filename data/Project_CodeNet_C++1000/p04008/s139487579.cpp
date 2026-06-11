#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,m,i,fa[N],he[N],lt[N],f[N],ans;
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void dfs(int x){
	for (int i=he[x];i;i=lt[i])
		dfs(i),f[x]=max(f[x],f[i]);
	if (++f[x]==m&&fa[x]!=1&&x!=1) f[x]=0,ans++;
}
int main(){
	n=read(),m=read();ans=read()!=1;
	for (i=2;i<=n;i++){
		int x=read();fa[i]=x;lt[i]=he[x];he[x]=i;
	}
	dfs(1);printf("%d",ans);
}