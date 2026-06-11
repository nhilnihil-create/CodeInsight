#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

long long a, b, n, h[N], ps[N];

bool chk(long long t) {
	long long res = 0;
   	for (int i = 1; i <= n; i++)
		if (h[i] >= t * b) {
			res += (h[i] - t * b) / (a - b);
			if ((h[i] - t * b) % (a - b))
				res++;
		}	
	return res <= t;
}

int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	sort (h + 1, h + n + 1);
	for (int i = n; i >= 1; i--)
		ps[i] = ps[i + 1] + h[i];
	long long l = 0, r = 1e9 + 100;
	while (r - l > 1) {
		long long md = (r + l) / 2;
		if (chk(md))
			r = md;
		else
			l = md;
	}
	cout << r;
	return 0;
}
