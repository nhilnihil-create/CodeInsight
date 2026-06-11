#include <iostream>
#include <cstdio>
#define N 305
using namespace std;

int n, a[N][N], v[N][N];
int main()
{
	int i,j, k, num;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j= 1; j <= n; j++) {
			scanf ("%d", &a[i][j]);
		}
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i == j) continue;
				num = a[i][k] + a[k][j];
				if (num < a[i][j]) {
					cout << -1;
					return 0;
				}
				if (num == a[i][j] && i != k && j != k) v[i][j] = 1;
			}
		}
	}
	long long s = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			s += a[i][j] * (1 - v[i][j]);
		}
	}
	cout << s / 2;
    return 0;
}
