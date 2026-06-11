#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cout << fixed << setprecision(30);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	set<int>water;
	for (int i = 0; i <= f / (a * 100); i++) {
		for (int j = 0; j <= f / (b * 100); j++) {
			int x = a * 100 * i + b * 100 * j;
			if(x!=0&&x<=f)water.insert(x);
		}
	}
	double_t ans = 0;
	int ans_w = 0;
	int ans_s = 0;
	for (auto w : water) {
		int sugmax = min(w * e / 100, f - w);
		int sugres = 0;
		for (int i = 0; i <= sugmax / c; i++) {
			for (int j = 0; j <= sugmax / d; j++) {
				int x = i * c + j * d;
				if (x <= sugmax)sugres = max(sugres, x);
				else break;
			}
		}
		double_t res = (double_t)sugres / (w + sugres);
		if (ans < res) {
			ans = res;
			ans_s = sugres;
			ans_w = w;
			//cout << res << endl;
		}
		//cout << sugres << " " << w << endl;
	}
	if (ans_s == 0) {
		cout << a * 100 << " " << 0 << endl;
		return 0;
	}
	cout << ans_w + ans_s << " " << ans_s << endl;
}