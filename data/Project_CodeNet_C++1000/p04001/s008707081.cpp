#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm> 
#include <cmath>

using namespace std;

typedef long long LL;

string str;
LL a[15];

int main() {
	cin >> str;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		a[i] = str[i] - '0';
	}

	LL ans = 0;
	for (int i = 0; i < (1 << (n - 1)); i++) {
		LL sum = 0;
		LL cur = a[0];
		for (int j = 0; j < n - 1; j++) {
			if (i & (1 << j)) {
				sum += cur;
				cur = a[j + 1];
			} else {
				cur = (cur * 10 + a[j + 1]);
			}
		}
		sum += cur;
		ans += sum;
	}
	cout << ans << endl;
}