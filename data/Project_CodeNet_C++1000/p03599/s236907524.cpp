#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int A,B,C,D,E,F; cin >> A >> B >> C >> D >> E >>F;

    double ma = 0;
    int water = 0, sugar = 0;
    int mawa = 0, masu = 0;
    for (int i = 0; i < (ll)ceil(F/((double)A * 100)); i++) {
        for (int j = 0; j < (ll)ceil(F/((double)B * 100)); j++) {
            if (i + j == 0) continue;
            water = i * A * 100 + j * B * 100; 
            if (water > F) break;
            for (int k = 0; water + k * C < F; k++) {
                for (int l = 0; ; l++) {
                    sugar = k * C + l * D;
                    if (water * E < sugar * 100) break;
                    if (water + sugar > F) break;
                    if (water * E == 100 * sugar) {
                        mawa = water;
                        masu = sugar;
                        goto END;
                    }
                    double c = 100 * (double)sugar / (water + sugar);
                    if (ma <= c) {
                        ma = c;
                        mawa = water;
                        masu = sugar;
                    }
                }
            }
        }
    }
END:
    cout << mawa + masu << " " << masu << endl;
}