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
#include<bitset>
using namespace std;
typedef long long LL;
const int N=2e5;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int a[N];
int head[N],nxt[N],to[N];
inline LL dfs(int k,int fa) {
	if (!nxt[head[k]])
		return a[k];
	LL s=a[k]<<1,t;
	for (int i=head[k];i;i=nxt[i])
		if (to[i]!=fa) {
			t=dfs(to[i],k);
			if (t>a[k]) puts("NO"),exit(0);
			s-=t;
		}
	if (s<0||s>a[k]) puts("NO"),exit(0);
	return s;
}
inline bool check(int n) {
	int i;
	for (i=1;i<=n;i++)
		if (nxt[head[i]])
			return !dfs(i,0);
	return a[1]==a[2];
}
int main()
{
	int n=gi(),i,a,b,tot=0;
	for (i=1;i<=n;i++) ::a[i]=gi();
	for (i=1;i<n;i++) {
		a=gi(),b=gi();
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot;
	}
	puts(check(n)?"YES":"NO");
	return 0;
}
