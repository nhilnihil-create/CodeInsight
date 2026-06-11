#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

int n, a[110000];
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int mi = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > mi + 1) {
			ans += (a[i] - 1) / (mi + 1);
			mi = max(mi, 1);
		}else {
			mi = max(mi, a[i]);
		}
	}
	// printf("%d\n", mi);
	cout << ans << endl;
}
