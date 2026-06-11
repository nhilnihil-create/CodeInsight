#include <iostream>
#include <utility>
using namespace std;

double concentration(double water, double suger) {
	return 100 * suger / (water + suger);
}

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	pair<double, pair<int, int>> a;
	for (int i = 0; i <= F; i += 100 * A) {
		for (int j = 0; i + j <= F; j += 100 * B) {
			for (int k = 0; i + j + k <= F; k += C) {
				for (int l = 0; i + j + k + l <= F; l += D) {
					if (!i && !j && !k && !l) continue;
					if (concentration(i + j, k + l) <= concentration(100, E)) {
						if (a.first <= concentration(i + j, k + l)) {
							a.first = concentration(i + j, k + l);
							a.second.first = i + j + k + l;
							a.second.second = k + l;
						}
					}
				}
			}
		}
	}
	cout << a.second.first << ' ' << a.second.second;
}