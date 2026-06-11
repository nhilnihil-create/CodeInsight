#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> T gi() {
	T x = 0; bool f = 0; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') f = 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f ? -x : x;
}
char c[] = {'R', 'Y', 'G', 'B'};
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int H = gi<int>(), W = gi<int>(), k = gi<int>();
	for (int i = 1; i <= H; i++, puts(""))
		for (int j = 1; j <= W; j++) {
			int x = i + j + 1000, y = i - j + 1000;
			printf("%c", c[((x / k) & 1) << 1 | ((y / k) & 1)]);
		}
	return 0;
}
