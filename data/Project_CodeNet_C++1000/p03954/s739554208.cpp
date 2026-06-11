#include<bits/stdc++.h>
#include <cstdio>
#include <cctype>
#include <cassert>
using namespace std;
inline char gc() {
	static const int L = 233333;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if (sss == ttt) {
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if (sss == ttt) {
			return EOF;
		}
	}
	return *sss++;
}

#ifdef _dfcmydd
#define dd c = getchar()
#else
#define dd c = gc()
#endif
template <class T>
inline bool read(T& x) {
	x = 0;
	char dd;
	bool flg = false;
	for (; !isdigit(c); dd) {
		if (c == '-') {
			flg = true;
		} else if (c == EOF) {
			return false;
		}
	}
	for (; isdigit(c); dd) {
		x = (x << 1) + (x << 3) + (c ^ 48);
	}
	if (flg) {
		x = -x;
	}
	return true;
}
#undef dd

template <class T>
inline void write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x | 48);
		return;
	}
	write(x / 10);
	putchar((x % 10) | 48);
}
int n,l,r;
int a[510000];
int pd(int num){
	if(a[n]<=num && (a[n-1]<=num || a[n+1]<=num))
		return 1;
	if(a[n]>num && (a[n-1]>num || a[n+1]>num))
		return 0;
	for(int i=1;i<n-1;i++){
		if((a[n+1+i]<=num && a[n+i]<=num) || (a[n-i-1]<=num && a[n-i]<=num))
			return 1;
		if((a[n+1+i]>num && a[n+i]>num) || (a[n-i-1]>num && a[n-i]>num))
			return 0;
	}
	return a[1]<=num;
}
int main() {
//	freopen("pyramid.in", "r", stdin);
//	freopen("pyramid.out", "w", stdout);
	read(n);
	for(int i=1;i<=n*2-1;i++)
		read(a[i]);
	l=1,r=n*2-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(pd(mid))
			r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}