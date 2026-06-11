#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long LL;
const int N=510*510;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int fa[N],f[N];
bool o[N];
int ans[N];
inline int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
int main()
{
	int n=gi(),i,p,k;
	for (i=1;i<=n*n;i++) fa[i]=i;
	for (i=1;i<=n;i++) {
		p=i,k=f[i]=gi();
		if (o[k]) return puts("No"),0;
		o[k]=true;
		while (p--) {
			k=find(k);
			if (!k) return puts("No"),0;
			ans[k]=i;
			fa[k]=k-1;
		}
		swap(ans[k],ans[f[i]]);
	}
	for (i=1,p=0;i<=n*n;i++)
		if (!o[i]&&ans[i]) {
			while (p<i&&ans[++p]);
			if (p!=i) {
				ans[p]=ans[i];
				ans[i]=0;
			}
		}
	for (i=1;i<=n*n;i++) fa[i]=ans[i]?i+1:i;
	for (i=1;i<=n;i++) {
		p=n-i,k=f[i]+1;
		while (p--) {
			k=find(k);
			if (!k) return puts("No"),0;
			ans[k]=i;
			fa[k]=k+1;
		}
	}
	puts("Yes");
	for (i=1;i<=n*n;i++) printf("%d ",ans[i]);
	return 0;
}
