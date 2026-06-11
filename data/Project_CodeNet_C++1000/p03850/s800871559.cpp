
/*
　　　　　／＞　 フ
　　　　　| 　_　 _|
　 　　　／`ミ _x 彡
　　 　 /　　　 　 |
　　　 /　  ヽ　　 ?
　／￣|　　 |　|　|
　| (￣ヽ＿_ヽ_)_)
　＼二つ
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

const int N = 200500;
int n;
char s[5];
ll f[N][3];
int op[N];
int main() {
	memset(f, -0x3f, sizeof(f));
	read(n); read(f[1][0]);
	for (int i = 2, x;i <= n; i++) {
		read(x);
		f[i][0] = max(f[i-1][1], f[i-1][0]) + x;
		f[i][1] = max(f[i-1][1], f[i-1][2]) - x;
		f[i][2] = f[i-1][2] + x;
		if (x < 0) Mx(f[i][2], f[i][1]), Mx(f[i][1], f[i][0]);
	}
	write(max(f[n][0], max(f[n][1], f[n][2])));
	return 0;
}