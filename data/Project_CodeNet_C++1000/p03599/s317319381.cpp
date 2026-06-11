#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    double max_dens = 0;
    int max_weight = 0;
    int max_sugar = 0;
    for (int i = 0; i * A * 100 <= F; i++) {
        for (int j = 0; (i * A + j * B) * 100 <= F; j++) {
            int water = (A * i + B * j) * 100;
            for (int k = 0; k * C + water <= F; k++) {
                for (int l = 0; k * C + l * D + water <= F; l++) {
                    int sugar = k * C + l * D;
                    if (sugar <= E * (water / 100) && water + sugar <= F) {
                        double density = 100.0 * sugar / (water + sugar);
                        if (density >= max_dens) {
                            max_weight = water + sugar;
                            max_sugar = sugar;
                            max_dens = density;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    cout << max_weight << ' ' << max_sugar << endl;
}
