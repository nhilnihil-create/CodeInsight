#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long
#define ri register int
#define max maxx
#define min minn
using namespace std;
const int N=1e5+10;
template <class T> void in(T &x) {
	x = 0;
	bool f = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = 1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	if (f) x = -x;
}
inline int maxx(int x,int y) {
	return x>y?x:y;
}
inline int minn(int x,int y) {
	return x<y?x:y;
}
inline int gcd(int x,int y) {
	return !y?x:gcd(y,x%y);
}
int l[N],cor[N],pos[N];
int a[N],dif[N],m,k,n,cnt,x;
vector<int> v[N];
inline void dfs(int x,int p) {
	l[x]=p;
	cor[x]=cnt;
	v[cnt].push_back(x);
	if(!cor[pos[x]])
		dfs(pos[x],++p);
}
signed main() {
	in(n);
	for(ri i=1; i<=n; ++i)
		in(a[i]),pos[i]=i,dif[i-1]=a[i]-a[i-1];
	in(m),in(k);
	for(ri i=1; i<=m; ++i)
		in(x),swap(pos[x],pos[x-1]);
	for(ri i=1; i<=n; i++)
		if(!l[i])
			cnt++,dfs(i,0);
	printf("%.1lf\n",(double)a[1]);
	int last=a[1];
	for(int i=1;i<n;i++)
		last+=dif[v[cor[i]][(l[i]+k)%v[cor[i]].size()]],printf("%.1lf\n",(double)last);
	return 0;
}