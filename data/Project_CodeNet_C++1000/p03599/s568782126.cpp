#include <bits/stdc++.h>
using namespace std;


int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    set<int> waterS, sugarS;

    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            int water = 100 * A * i + 100 * B * j;
            if (water <= F)
                waterS.insert(water);
        }
    }

    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 3000; j++) {
            int sugar = i * C + j * D;
            if (sugar <= F)
                sugarS.insert(sugar);
        }
    }
    double max_v = -1e20;
    int max_s=0, max_f = 0;

    for (auto water : waterS) {
        for (auto sugar : sugarS) {
            int sum = water + sugar;
            if (sum > F)
                continue;
            double per = ((double) (100 * sugar)) / (double) (sum);
            if (per > max_v && (water / 100 * E) >= sugar) {
                max_s = sugar;
                max_f = sum;
                max_v = per;
            }
        }
    }
    cout << max_f << " " << max_s << endl;
}