#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int h[n];
	for (int i = 0;i < n;i++)cin >> h[i];
	sort(h, h + n);
	ll right = h[n - 1], left = 0;
	while (right - left > 1) {
		ll mid = (right + left) / 2;
		ll sum = 0;
		for (int i = 0;i < n;i++) {
			if (h[i] > b*mid) {
				if ((h[i] - b * mid) % (a - b) == 0)sum += (h[i] - b * mid) / (a - b);
				else sum += (h[i] - b * mid) / (a - b) + 1;
			}
		}
		if (sum > mid) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << right << endl;
}