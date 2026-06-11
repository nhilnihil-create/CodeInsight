#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    double A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    int maxW = A * 100, maxS = 0;
    double maxC = 0.0;

    for (int m = 0; m <= 30; m++) {
        for (int n = 0; n <= 30; n++) {
            double water = 100 * (A * m + B * n);
            double rest = F - water;
            if (rest <= 0) continue;

            double upperS = min((A * m + B * n) * E, rest);
            double sugar = 0;
            for (int s = 0; C * s <= upperS; s++) {
                int t = (upperS - C * s) / D;
                sugar = max(sugar, C * s + D * t);
            }

            double curC = sugar / (water + sugar);
            if (curC > maxC) { maxC = curC, maxW = water, maxS = sugar; }
        }
    }

    cout << maxW + maxS << ' ' << maxS << '\n';
}
