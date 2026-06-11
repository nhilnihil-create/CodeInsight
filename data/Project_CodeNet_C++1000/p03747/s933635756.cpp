#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

const int N=200005;

int a[N];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

int main(void) {
	int n=read(),m=read(),T=read();
	int id=0;
	rep(i,0,n-1) {
		int x=read(),w=read();
		if (w==1) {
			id+=(x+T)/m;
			a[i]=(x+T)%m;
		} else {
			if ((x-T)%m<0) {
				a[i]=(x-T)%m+m;
				id+=(x-T)/m-1;
			} else {
				a[i]=(x-T)%m;
				id+=(x-T)/m;
			}
		}
	}
	std:: sort(a,a+n);
	id=(id%n+n)%n;
	rep(i,id,n-1) printf("%d\n", a[i]);
	rep(i,0,id-1) printf("%d\n", a[i]);
	return 0;
}