#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PRINT(s) cout << s << endl;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR((i), 0, (n))

int main() {
    int k, s;
    cin >> k >> s;
    int limit = min(k, s) + 1;
    int count = 0;
    REP(x, limit) {
        if (2 * k + x < s) continue;
        REP(y, limit) {
            if (k + x + y < s || x + y > s) continue;
            count += 1; 
        }
    }
    PRINT(count);
}
