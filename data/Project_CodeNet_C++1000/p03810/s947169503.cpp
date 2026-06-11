/*
	有奇数个偶数,先手赢
	有偶数个偶数,先手也不一定会输
*/
#include <iostream>
#include <cstdio>
#define N 100005

using namespace std;

int n;
int a[N];

inline int gcd(int u, int v) { return v ? gcd(v, u % v) : u; }

inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

bool solve() {
	int cntEven = 0;
	bool flagOne = false;
	for(int i = 1; i <= n; ++i) {
		if(~a[i] & 1) {
			++cntEven;
		} else if(a[i] == 1) {
			flagOne = true;
		}
	}
	if(cntEven & 1) {
		return true;
	} else {
		if(flagOne || cntEven != n - 1) return false;
		int Gcd = 0;
		for(int i = 1; i <= n; ++i)
			Gcd = gcd(a[i] & 1 ? a[i] - 1 : a[i], Gcd);
		for(int i = 1; i <= n; ++i)	a[i] /= Gcd;
		bool flag = solve() ^ 1;
		for(int i = 1; i <= n; ++i) a[i] *= Gcd;
		return flag;
	}
}

int main() {
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	puts(solve() ? "First" : "Second");
	return 0;
}