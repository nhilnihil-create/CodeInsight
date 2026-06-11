#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main() {

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	double condence = -1;
	int sugar = 0;
	int water = 0;

	for (int i = 0; i < (f+(100*a)-1)  / (100*a); i++) {

		for (int j = 0; j < (f + (100 * b) - 1) / (100*b); j++) {
			
			for (int l = 0; l < (f+c-1)/c; l++) {

				for (int m = 0; m < (f+d-1)/d ; m++) {
					
					if ((c * l + m * d + 100 * a * i + 100 * b * j)> f) {
						break;
					}

					double sugar1 = c * l + m * d;
					double total = c * l + m * d + 100 * a * i + 100 * b * j;

					double con = (double)100 * sugar1 / total;
					
					if (e * (100 * a * i + 100 * b * j) >= (c * l + m * d) *100 && condence < con) {
						condence = con;
						water = 100 * a * i + 100 * b * j;
						sugar = c * l + d * m;
					}
				}
			}
			
		}
	}

	cout << water + sugar << " " << sugar << endl;

	return 0;
}