#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	vector<int> water;
	for (int i = 0; i < f; i += a * 100) {
		for (int j = 0; i + j < f; j += b * 100) {
			water.emplace_back(i + j);
		}
	}

	int w_s_max;
	int w_t;
	int mx = 0;
	int t;
	int ans_s = 0;
	int ans_w = 0;
	for (int i = 0; i < water.size(); i++) {
		w_t = 0;
		w_s_max = water[i] * e / 100;
		for (int j = 0; j <= w_s_max; j += c) {
			for (int k = 0; j + k <= w_s_max; k += d) {
				if (water[i] + j + k <= f) {
					t = 100.0 * (j + k);
					if (t * ans_w >= mx * (water[i] + j + k)) {
						mx = t;
						ans_s = j + k;
						ans_w = ans_s + water[i];
					}
				}
			}
		}
	}
	if (ans_w == 0) {
		printf("%d %d\n", 100 * a, 0);
	}
	else {
		printf("%d %d\n", ans_w, ans_s);
	}

	return 0;
}