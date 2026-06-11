#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
int main() {
	char t[2][2];
	t[0][0] = 'R', t[0][1] = 'Y';
	t[1][0] = 'G', t[1][1] = 'B';
	int h, w, d; read(h), read(w), read(d);
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			int x = (i + j) / d, y = (i - j + w) / d;
			int tx = x & 1, ty = y & 1;
			putchar(t[tx][ty]);
		}
		putchar('\n');
	}
	return 0;
}

