#include<cstdio>
#include<iostream>
#define gmax(x, y) if ((y) > x) x = (y);
using namespace std;
typedef long long ll;
inline char nc() {
	static char b[1<<12],*s=b,*t=b;
	return s==t&&(t=(s=b)+fread(b,1,1<<12,stdin),s==t)?-1:*s++;
}
template < class T >
inline void read(T &x) {
	char b = nc(); x = 0;
	for (; !isdigit(b); b = nc());
	for (; isdigit(b); b = nc()) x = x * 10 + b - '0';
}
inline ll read() {
	char b = nc();
	for (; b != '-' && b != '+'; b = nc());
	return b == '-' ? -1 : 1;
}
int n;
ll f0, f1, f2;
int main() {
	read(n); read(f0); f1 = f2 = -1e15;
	for (int a, op, i = 1; i < n; ++i) {
		op = read(); read(a);
		f0 += a * op; f1 -= a * op; f2 += a * op;
		if (op == -1) {
			gmax(f2, f1); gmax(f1, f0);
		} gmax(f1, f2); gmax(f0, f1);
	} printf("%lld\n", f0);
	return 0;	
}
