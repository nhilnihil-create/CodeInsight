#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    A *= 100;
    B *= 100;

    double cardMax = 0;
    int waterMax = 0;
    int sugarMax = 0;

    int nA = F / A;
    for (int i=0; i<=nA; ++i) {
        int nB = (F - i *  A) / B;
        for (int j=0; j<=nB; ++j) {
            int water = i*A + j*B;
            if (water == 0) continue;

            int sMax100 = E * water; // E * (water / 100.0)
            sMax100 = min(sMax100, 100*(F-water));
            for (int sC=0; sC<=sMax100; sC+=100*C) {
                int sDMax100 = sMax100 - sC;
                for (int sD=0; sD<=sDMax100; sD+=100*D) {
                    //if ((water + sC + sD) > F) continue;
                    double card = double(sC + sD) / water;
                    if (card > cardMax) {
                        cardMax = card;
                        waterMax = water;
                        sugarMax = sC + sD;
                    }
                }
            }
        }
    }

    if (waterMax == 0) waterMax = A;
    cout << waterMax + sugarMax/100 << ' ' << sugarMax/100 << endl;;
    return 0;
}
