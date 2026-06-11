#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cassert>

using namespace std;

const int N = 1e5 + 7;
const long long INF = 1LL << 60;
int n;
int a[N];
char sign[N];
long long base = 0;

int main() {
	scanf("%d", &n);
	cin >> base;
	long long all = 0;
	for (int i = 1; i < n; i++) {
		char buffer[10];
		scanf("%s %d", buffer, &a[i]);
		sign[i] = buffer[0];
		all += a[i];
	}
	long long ans = -INF;
	for (int i = 1; i < n; i++) {
		if (sign[i] == '-') {
			long long middle = 0;
			int j;
			for (j = i + 1; j < n; j++) {
				if (sign[j] == '-') {
					break;
				} else {
					middle += a[j];
				}
			}
			ans = max(ans, all - 2 * a[i] - 2 * middle + base);
			base -= a[i];
		} else {
			base += a[i];
		}
		all -= a[i];
	}
	cout << max(base, ans) << endl;
	return 0;
}
