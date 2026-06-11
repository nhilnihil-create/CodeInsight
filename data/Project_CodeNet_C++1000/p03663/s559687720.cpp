//#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//ifstream cin("x.in"); ofstream cout("x.out");

string s;

bool ok (long long x) {
    if (x == 0) return 0;

    cout << "? " << x << "\n"; cout.flush();

    cin >> s;
    if (s == "Y") return 1;
    else          return 0;
}

int main() {
    long long p10 = 1, p9 = 9;
    long long ans = 0;

    int nrcif = 0;
    for (int i = 0; i <= 9; ++ i) {
        if (!ok(p10)) {
            nrcif = i; break;
        }
        p10 *= 10;
    }

    if (nrcif == 0) { // rasp e 10^x
        ans = 1;
        for (int i = 1; i <= 9; ++ i) {
            if (ok(p9)) {
                break;
            }
            ans *= 10;
            p9 = p9 * 10 + 9;
        }
    } else {
        for (int i = 1; i < nrcif; ++ i) {
            int sol = 0;
            ans *= 10;
            for (int step = 8; step > 0; step >>= 1) {
                if (sol + step < 10 && ok(ans + sol + step)) {
                    sol += step;
                }
            }
            ans += sol;
        }

        // ptr ultima cifra
        int sol = 9;
        ans *= 10;
        for (int step = 8; step > 0; step >>= 1) {
            if (sol - step >= 0 && ok((ans + sol - step) * 10)) {
                sol -= step;
            }
        }
        ans += sol;
    }

    cout << "! " << ans << "\n"; cout.flush();
    return 0;
}
