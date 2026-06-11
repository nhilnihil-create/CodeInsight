#pragma GCC optimize (2)
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
using namespace std;
struct tt{int l, r, sum;}t[6000010];
struct aa{int x, y;}a[N];
int n, m, l, root[N], ans, now, l1, x;
inline char gc(){
	static char now[1<<16], *S, *T;
	if(S==T){T=(S=now)+fread(now, 1, 1<<16, stdin); if(S==T)return EOF;}
	return *S++;
}
inline int read(){
	int x=0, f=1; char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=gc();}
	return x*f;
}
inline bool cmp(aa a, aa b){return a.x<b.x;}
inline void ins(int i, int x, int L, int R){
	t[l]=t[i]; t[l].sum++;
	if(L<R){
		int mid=(L+R)>>1, l1=l;
		if(x<=mid){l++; t[l1].l=l; ins(t[i].l, x, L, mid);}
		else{l++; t[l1].r=l; ins(t[i].r, x, mid+1, R);}
	}
}
inline int csum(int x1, int x2, int a, int b, int L, int R){
	if(a<=L&&R<=b)return t[x1].sum-t[x2].sum;
	int mid=(L+R)>>1, s=0;
	if(a<=mid)s+=csum(t[x1].l, t[x2].l, a, b, L, mid);
	if(mid<b)s+=csum(t[x1].r, t[x2].r, a, b, mid+1, R);
	return s;
}
int main(){
	n=read(); m=read();
	for(int i=1; i<=n; i++){a[i].x=read(); a[i].y=read();}
	sort(a+1, a+1+n, cmp);
	l=root[0]=now=0;
	for(int i=1; i<=m; i++){
		root[i]=root[i-1];
		while(now<n&&a[now+1].x==i){
			now++;
			l++; l1=l; ins(root[i], a[now].y, 1, m); root[i]=l1;
		}
	}
	printf("%d\n", n);
	for(int i=2; i<=m; i++){
		ans=n;
		for(x=i; x<=m; x+=i)ans-=csum(root[x-1], root[x-i], x-i+1, x-1, 1, m);
		x-=i; if(x<m)ans-=csum(root[m], root[x], x+1, m, 1, m);
		printf("%d\n", ans);
	}
	return 0;
}