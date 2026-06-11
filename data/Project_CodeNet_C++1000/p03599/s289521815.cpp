#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    set<int> sugarS;
    set<int> waterS;
    int i, j;
    for(i = 0; i < 31; i++) {
        for(j = 0; j < 16; j++) {
            int water = i*a*100 + j*b*100;
            if (water <= f) {
                waterS.insert(water);
            }
        }
    }
    for(i = 0; i < 3001; i++) {
        for(j = 0; j < 1501; j++) {
            int sugar = i*c + j*d;
            if (sugar <= f) {
                sugarS.insert(sugar);
            }
        }
    }

    const double lim = (double)e / (100+e);
    double per = -1;
    int ans1 = 0,
        ans2 = 0;
    for(auto sugar : sugarS) {
        for(auto water : waterS) {
            int sum = water + sugar;
            if (sum == 0) {
                continue;
            }
            double x = (double)sugar / sum;
            if (sum <= f && x <= lim && x > per) {
                    per = x;
                    ans1 = sum;
                    ans2 = sugar;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
}
