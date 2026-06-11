#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double mx = -1.0;
	int mx_water = a, mx_sugar = 0;
	for(int ia = 1; (a * ia) * 100 <= f; ia++) {
		for(int ib = 0; (a * ia + b * ib) * 100 <= f; ib++) {
			int water = (a * ia + b * ib) * 100;
			for(int ic = 0; water + c * ic <= f; ic++) {
				for(int id = 0; water + c * ic + d * id <= f; id++) {
					int sugar = c * ic + d * id;
					if(water + sugar > f) break;
					if(water/100 * e < sugar) break;
					double now = 100.0 * (double) sugar / (water + sugar);
					if(mx < now) {
						mx = now;
						mx_water = water;
						mx_sugar = sugar;
					}
				}
			}
		}
	}
	printf("%d %d\n", mx_water + mx_sugar, mx_sugar);
	return 0;
}