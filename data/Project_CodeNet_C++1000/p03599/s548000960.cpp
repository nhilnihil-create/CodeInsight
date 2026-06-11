#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void c_sugar_water(void) {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	// 上限
	// 合計がFを超える
	// 100gあたりの砂糖の量がEを超える
	// a+b+c+dがf以下
	// (c+d)/(a*x+b*y) <= E
	// 100*a*x + 100*b*y
	// c*z + d*w
	int water_max = 0;
	int sugar_max = 0;
	float nodo_max;
	int water = 0;
	int sugar = 0;
	int water_a = 0;
	int water_b = 0;
	int sugar_c = 0;
	int sugar_d = 0;

	float limit = (e*100.0) / (100 + e);

	nodo_max = 0;
	water_max = 100 * a;
	for (int x = 0; (100*a*x) <= f; x++) {
		water_a = 100 * a * x;
		for (int y = 0; (100*b*y) <= (f-water_a); y++) {
			if ((x == 0) && (y == 0))continue;
			water_b = 100 * b * y;
			for (int z = 0; (z*c) <= (f-water_a-water_b); z++) {
				sugar_c = z * c;
				for (int w = 0; (w*d) <= (f-water_a-water_b-sugar_c); w++) {
					sugar_d = w * d;
					water = water_a + water_b;
					sugar = sugar_c + sugar_d;
					//if (((sugar_c + sugar_d) / (a*x + b*y)) > e)break;
					if (water + sugar > f) break;
					float nodo = 100.0 * sugar / (water + sugar);
					if (nodo > limit)break;
					//cout << water<<" "<<sugar<<" "<<nodo <<" "<<nodo_max<< endl;
					if (nodo > nodo_max) {
						water_max = water+sugar;
						sugar_max = sugar;
						nodo_max = nodo;
					}
				}
			}
		}
	}

	cout << water_max << " " << sugar_max << endl;

}

int main()
{
	c_sugar_water();
    return 0;
}