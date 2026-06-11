#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
#include <complex>
#define int long long
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x){
	write(x);puts("");
}
const int N=1e5+10;
struct ppap{int x,v;}a[N];
int n,ans[N];
inline bool cmp(ppap a,ppap b){return a.v>b.v;}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++){
		a[i].v=read();a[i].x=i;
	}
	sort(a+1,a+n+1,cmp);
	int minn=a[1].x;
	for(int i=2;i<=n;i++){
		int rp=a[i-1].v-a[i].v;
		ans[minn]+=(i-1)*rp;
		minn=min(minn,a[i].x);
	}
	ans[minn]+=n*a[n].v;
	for(int i=1;i<=n;i++)writeln(ans[i]);
	return 0;
}