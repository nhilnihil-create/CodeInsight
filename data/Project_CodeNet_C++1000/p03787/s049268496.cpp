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
const int N=1e5+100;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int fa[N];bool odd[N],two[N],d[N];
inline int find(int x) {
	if (fa[x]==x) return x;
	find(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=fa[fa[x]];
}
int main()
{
	int n=gi(),m=gi(),i,a,b;
	for (i=1;i<=n;i++) fa[i]=i;
	while (m--) {
		a=gi(),b=gi();
		if (find(a)!=find(b)) {
			two[a]=true;
			odd[fa[a]]|=odd[fa[b]];
			d[fa[b]]=d[b]^1;
			fa[fa[b]]=a;
		} else odd[fa[a]]|=d[a]^d[b]^1;
	}
	int A=0,B=0,C=0;
	for (i=1;i<=n;i++)
		if (fa[i]==i)
			(two[i]?(odd[i]?A:B):C)++;
	cout<<1LL*C*C+2LL*C*(n-C)+2LL*A*B+1LL*A*A+2LL*B*B;
	return 0;
}
