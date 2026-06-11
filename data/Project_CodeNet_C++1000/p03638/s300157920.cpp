#include <bits/stdc++.h>
using namespace std;

int h, w, n, c[10000];

int main() {
	cin >> h >> w >> n;
	for (int i = 0, j = 0, a; i < n; i++) {
		cin >> a;
		while (a--)
			c[j++] = i + 1;
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cout << c[w * i + (i & 1 ? w - 1 - j : j)]
					<< (j < w - 1 ? " " : "\n");
}
