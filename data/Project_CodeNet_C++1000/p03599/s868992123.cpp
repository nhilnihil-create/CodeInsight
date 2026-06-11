#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    int water_max = 0;
    int sugar_max = 0;
    double conc_max = 0;
    int water, sugar;
    double conc;
    for (int i = 0; 100 * A * i <= F; i++) {
        for (int j = 0; 100 * A * i + 100 * B * j <= F; j++) {
            if (i + j != 0) {
                for (int k = 0; 100 * A * i + 100 * B * j + C * k <= F; k++) {
                    for (int l = 0; 100 * A * i + 100 * B * j + C * k + D * l <= F; l++) {
                        water = 100 * A * i + 100 * B * j;
                        sugar = C * k + D * l;
                        if (water + sugar <= F && 100.0 * sugar / water <= E) {
                            conc = 100.0 * sugar / (water + sugar);
                            if (conc >= conc_max) {
                                conc_max = conc;
                                water_max = water;
                                sugar_max = sugar;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << water_max + sugar_max << " " << sugar_max << endl;
}
