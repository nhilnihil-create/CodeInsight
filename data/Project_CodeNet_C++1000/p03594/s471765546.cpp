#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
const int N = 5e2 + 5;
int n, m, d, ans[N][N + N];
int main() {
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x = i + j;
			int y = i - j + m;
			x /= d; y /= d;
			x &= 1; y &= 1;
			ans[i][j] = x + (y << 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ans[i][j] == 0) printf("R");
			if (ans[i][j] == 1) printf("Y");
			if (ans[i][j] == 2) printf("G");
			if (ans[i][j] == 3) printf("B");
		}
		printf("\n");
	}
}