#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
#define ll long long
int pos[N],a[N];
ll p[N],d[N];
int to[N][64];
int main (){
	int n;scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%lld",&p[i]),d[i]=p[i]-p[i-1];
	int m;ll k;
	scanf ("%d%lld",&m,&k);
	for (int i=1;i<=n;i++) a[i]=i;
	for (int i=1,x;i<=m;i++) {scanf ("%d",&x);swap(a[x],a[x+1]);}
	for (int i=1;i<=n;i++) to[a[i]][0]=i;
	for (int i=1;i<=60;i++)
		for (int j=1;j<=n;j++)
			to[j][i]=to[to[j][i-1]][i-1];
	for (int i=1;i<=n;i++){
		int now=i;
		for (int j=0;j<=60;j++)
			if (k&(1ll<<j)) now=to[now][j];
		pos[now]=i;
	}
	for (int i=1;i<=n;i++) p[i]=p[i-1]+d[pos[i]],printf ("%lld\n",p[i]);
	return 0;
}
