//Serene
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
#define db double
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
const int maxn=2e5+7;
int n,m,ans,a[maxn];

char cc;ll ff;
template<typename T>void read(T& aa) {
	aa=0;cc=getchar();ff=1;
	while((cc<'0'||cc>'9')&&cc!='-') cc=getchar();
	if(cc=='-') ff=-1,cc=getchar();
	while(cc>='0'&&cc<='9') aa=aa*10+cc-'0',cc=getchar();
	aa*=ff;
}

int fir[maxn],nxt[maxn],to[maxn],e=0;
void add(int x,int y) {
	to[++e]=y;nxt[e]=fir[x];fir[x]=e;
}

int dep[maxn],rd[maxn];
void dfs(int pos,int d,int f) {
	dep[pos]=rd[pos]=d; int y,z;
	for(y=fir[pos];y;y=nxt[y]) {
		dfs(z=to[y],d+1,pos);
		rd[pos]=max(rd[pos],rd[z]);
	}
	if(f>1&&rd[pos]-dep[pos]+1==m) {
		rd[pos]=0;
		++ans;
	}
}

int main() {
	read(n); read(m);
	For(i,1,n) read(a[i]);
	if(a[1]!=1) ++ans,a[1]=1;
	For(i,2,n) add(a[i],i);
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
