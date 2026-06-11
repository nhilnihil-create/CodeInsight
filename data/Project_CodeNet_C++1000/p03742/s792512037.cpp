#include <bits/stdc++.h>
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int main() {
	int x, y; read(x), read(y);
	puts(abs(x-y) <= 1 ? "Brown" : "Alice");
	return 0;
}
