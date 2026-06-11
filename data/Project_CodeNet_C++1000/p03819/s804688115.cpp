//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a),i##ed=(b);i<=i##ed;i++)
#define per(i,a,b) for(int i=(a),i##ed=(b);i>=i##ed;i--)
using namespace std;
const int N=300010;
int n,m,sum,pos,res;
int t[N];
struct P {
	int x,y;
	inline bool operator<(const P &yy)const { return y-x<yy.y-yy.x; }
};P a[N];

inline void add(int x,int w) { for(;x<=m;x+=x&-x) t[x]+=w; }
inline int ask(int x) { int s=0;for(;x;x-=x&-x) s+=t[x];return s; }
int main() {
	scanf("%d%d",&n,&m),sum=n,pos=1;
	rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	rep(i,1,m) {
		for(;a[pos].y-a[pos].x+1<i&&pos<=n;)
			add(a[pos].x,1),add(a[pos].y+1,-1),++pos,--sum;
		res=0; rep(j,1,m/i) res+=ask(j*i);
		printf("%d\n",res+sum);
	}
	return 0;
}