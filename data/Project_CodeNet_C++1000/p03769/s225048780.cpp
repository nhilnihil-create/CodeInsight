
/*
???????????????? ??
??????????| ??_?? _|
?? ????????`?? _x ??
???? ?? /?????? ?? |
?????? /??  ?c???? ?
??????|???? |??|??|
??| (???c??_?c_)_)
???ܶ???
 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 2500;
ll n;
int q[N], l, r;
int cnt;

void solve(ll n) {
	if (!n) return; 
	if (n & 1) solve(n >> 1), cnt++, q[++r] = cnt;
	else solve(n - 1), cnt++, q[--l] = cnt;
}

int main() {
	l = 500, r = l - 1, read(n), solve(n);
	write(cnt + 100);
	for (int i = l;i <= r; i++) write(q[i], ' ');
	for (int i = 1;i <= 100; i++) write(i, ' ');
	return 0;
}