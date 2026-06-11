#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> a[100001];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x%m][x / m]++;
	}
	int res = 0;
	for (int i = 0; i <= m - i; i++) {
		if (i == 0 || i == m - i) {
			int sum = 0;
			for (map<int, int>::iterator it = a[i].begin(); it != a[i].end(); it++)
				sum += it->second;
			res += sum / 2;
		}
		else {
			int odd1 = 0, odd2 = 0, sum1 = 0, sum2 = 0;
			for (map<int, int>::iterator it = a[i].begin(); it != a[i].end(); it++) {
				odd1 += it->second % 2;
				sum1 += it->second - it->second % 2;
			}
			for (map<int, int>::iterator it = a[m - i].begin(); it != a[m - i].end(); it++) {
				odd2 += it->second % 2;
				sum2 += it->second - it->second % 2;
			}
			if (odd1 > odd2) {
				swap(odd1, odd2);
				swap(sum1, sum2);
			}
			res += odd1;
			odd2 -= odd1;
			odd2 -= odd2 % 2;
			if (sum1 >= odd2) res += odd2 + (sum1 - odd2) / 2 + sum2 / 2;
			else res += sum1 + sum2 / 2;
		}
	}
	printf("%d\n", res);
	return 0;
}