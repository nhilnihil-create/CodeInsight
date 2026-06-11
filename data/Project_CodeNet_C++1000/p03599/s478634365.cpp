#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int A, B, C, D, E, F;
int p1, p2;
double ans;
int main() {
    cin >> A >> B >> C >> D >> E >> F;
    // cc + dd + 100aa + 100bb / (100aa + 100bb)
    for (int a = 0; a <= 30; ++a) {
        for (int b = 0; b <= 30; ++b) {
            int water = a * A * 100 + b * B * 100;
            if (water > F) continue;
            int mx = min(water / 100 * E, F - water);
            for (int c = 0; c * C <= mx; ++c) {
                for (int d = 0; c * C + d * D <= mx; ++d) {
                    int su = c * C + d * D;
                    double den = su * 100.0f / (su + water);
                    if (den >= ans) {
                        ans = den;
                        p1 = su + water;
                        p2 = su;
                    }
                }
            }
        }
    }
    cout << p1 << ' ' << p2 << endl;
    return 0;
}
