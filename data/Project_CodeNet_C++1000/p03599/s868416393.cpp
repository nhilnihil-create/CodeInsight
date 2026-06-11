#include "bits/stdc++.h"
using namespace std;

int main() {
	double A, B, C, D, E, F;
	double ansW = 0.0, ansS = 0.0, ansD = 0.0, Water = 0.0, Suger = 0.0, Density = 0.0;
	cin >> A >> B >> C >> D >> E >> F;
	for (int a = 0; a <= 30; a++) {
		if (A * a * 100 > F) break;
		for (int b = 0; b <= 30; b++) {
			Water = (A * a + B * b) * 100;
			if (Water > F) break;
			for (int c = 0; c <= F; c++) {
				if (Water + C * c > F) break;
				for (int d = 0; d <= F; d++) {
					Suger = C * c + D * d;
					if (Water + Suger > F) break;
					Density = Suger / (Water + Suger);
					if (Density * 100 >= ansD && Density <= E / (100 + E)) {
						ansD = Density * 100;
						ansW = Water, ansS = Suger;
					}
				}
			}
		}
	}
	cout << ansW + ansS << " " << ansS;
}
