#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10;

inline void Read(int &x) {
	x = 0; register char cc = '\0'; int fff = 1;
	for (; cc < '0' || cc > '9'; cc = getchar())
		if (cc == '-') fff = -1;
	for (; cc >= '0' && cc <= '9'; cc = getchar())
		x = (x << 1) + (x << 3) + (cc & 15);
	x *= fff;
}

int n, mxn, a[N], b[N];

inline int Check(int x) {
	for (int i = 1; i <= mxn; ++i)
		if (a[i] <= x) b[i] = 0;
		else b[i] = 1;
	if (mxn == 1) return b[1];
	//printf("%d : ", x);
	//for (int i = 1; i <= mxn; ++i) printf("%d ", b[i]);
	//printf("\n");
	for (int i = 0; i < n - 1; ++i) {
		if (b[n - i] == b[n - i - 1]) return b[n - i];
		if (b[n + i] == b[n + i + 1]) return b[n + i];
	}
	if (n & 1 /*mxn & 1*/) return b[n];
	else return (!b[n]);
}

int main()
{
	Read(n);
	mxn = n * 2 - 1;
	for (int i = 1; i <= mxn; ++i) Read(a[i]);
	int L = 1, R = mxn/* n */, mid = 0, fps = 0;
	while (L <= R) {
		mid = (L + R) >> 1;
		if (!Check(mid)) {
			fps = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}
	printf("%d\n", fps);
	
	return 0;
}
