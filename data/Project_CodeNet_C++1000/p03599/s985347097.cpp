#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	a *= 100; b *= 100;


	pair<int, int> ans;
	ans.first = a, ans.second = 0;
	for (int wa = 0; wa < 39; wa++) {
		for (int wb = 0; wb < 39; wb++) {
			int water = wa * a + wb * b;
			if (water >= f) break;
			
			int sugar = 0;
			for (int sc = 0; sc < 1509; sc++) {
				for (int sd = 0; sd < 1509; sd++) {
					if (sc * c + sd * d > f - water) break;
					if ((sc * c + sd * d) * 100 > e * water) break;
					sugar = max(sugar, sc * c + sd * d);
				}
			}

			if (ans.second * (water + sugar) < sugar * ans.first) {
				ans.first = water + sugar; ans.second = sugar;
			}
		}
	}

	cout << ans.first << " " << ans.second << endl;
}