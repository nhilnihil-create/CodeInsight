#include<bits/stdc++.h>
#define N 100002
using namespace std;
inline int read(){
	int x=0; bool f=1; char c=getchar();
	for(;!isdigit(c); c=getchar()) if(c=='-') f=0;
	for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	if(f) return x; return 0-x;
}
int n,L,T,cnt;
struct ants{int x,w;}a[N];
inline bool cmp(ants a, ants b){
	return a.x<b.x;
}
int main(){
	n=read(), L=read(), T=read();
	for(int i=0; i<n; ++i){
		a[i].x=read(), a[i].w=read();
		a[i].x+=(a[i].w==1)?T:-T;
		cnt+=a[i].x/L;
		if(a[i].x%L<0) --cnt;
		cnt=(cnt%n+n)%n;
		a[i].x=(a[i].x%L+L)%L;
	}
	sort(a,a+n,cmp);
	for(int i=cnt; i<n; ++i) printf("%d\n",a[i].x);
	for(int i=0; i<cnt; ++i) printf("%d\n",a[i].x);
	putchar('\n');
	return 0;
}