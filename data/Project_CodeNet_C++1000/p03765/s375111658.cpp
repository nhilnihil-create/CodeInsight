#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e5 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7;

ll cnt[52][27];
ll pr[SIZE][2], pr2[SIZE][2];


int main() {
    fastInp;

    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        ll q = 1, q2 = 2;
        if (s[i] != 'A') {
            q = 2;
            q2 = 1;
        }
        pr[i + 1][0] = pr[i][0] + q;
        pr2[i + 1][0] = pr2[i][0] + q2;
    }

    for (int i = 0; i < t.size(); i++) {
        ll q = 1, q2 = 2;
        if (t[i] != 'A') {
            q = 2;
            q2 = 1;
        }
        pr[i + 1][1] = pr[i][1] + q;
        pr2[i + 1][1] = pr2[i][1] + q2;
    }
    ll q;
    cin >> q;
    while (q--) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        bool fl = (pr2[r1][0] - pr2[l1 - 1][0]) % 3 == (pr2[r2][1] - pr2[l2 - 1][1]) % 3;
        if (((pr[r1][0] - pr[l1 - 1][0]) % 3 == (pr[r2][1] - pr[l2 - 1][1]) % 3) || fl) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

