//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

ll n, a, b, h[MAXN], ans, l = -1, r;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	sort(h + 1, h + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		if (h[i] <= r * b)
			break;
		r += (h[i] - r * b + a - 1) / a;
	}
	while (l + 1 < r) {
		ll mid = (l + r) / 2, res = 0;
		for (int i = 1; i <= n; i++)
			if (h[i] - mid * b > 0)
				res += (h[i] - mid * b + (a - b - 1)) / (a - b);
		if (res > mid)
			l = mid;
		else
			r = mid;
	}
	cout << r << endl;	
	return 0;
}
