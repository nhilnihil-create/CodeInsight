#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double max = 0;
	int ans1 = 0, ans2 = 0;
	for (int i = 0; 100 * a * i <= f; i++) {
		for (int j = 0; 100 * a * i + 100 * b * j <= f; j++) {
			for (int k = 0; 100 * a * i + 100 * b * j + c * k <= f; k++) {
				for (int l = 0; 100 * a * i + 100 * b * j + c * k + d * l <= f; l++) {
					if (max <= double(100 * (c * k + d * l)) / double((100 * a * i + 100 * b * j + c * k + d * l)) && double(100 * (c * k + d * l)) / double((100 * a * i + 100 * b * j + c * k + d * l)) <= double(100 * e) / double(100 + e)) {
						max = double(100 * (c * k + d * l)) / double((100 * a * i + 100 * b * j + c * k + d * l));
						ans1 = 100 * a * i + 100 * b * j + c * k + d * l;
						ans2 = c * k + d * l;
					}
				}
			}
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
