#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    set<int> w = {};
    for (int i = 0; i < 3001; i++) {
        for (int j = 0; j < 3001; j++) {
            int x = A * i * 100 + B * j * 100;
            if (x > F) continue;
            w.insert(x);
        }
    }

    set<int> s = {};
    for (int i = 0; i < 3001; i++) {
        for (int j = 0; j < 3001; j++) {
            int x = i * C + j * D;
            if (x > F) continue;
            s.insert(x);
        }
    }

    int ans1;
    int ans2;
    double con = -1;
    double t_con = (double) E / ((double) 100 + (double) E);
    for (auto x : w) {
        for (auto y : s) {
            if (x + y > F) continue;

            double ncon = (double) y / ((double) x + (double) y);
            if (ncon > t_con) {
                continue;
            }

            if (ncon > con) {
                ans1 = x + y;
                ans2 = y;
                con = ncon;
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
}