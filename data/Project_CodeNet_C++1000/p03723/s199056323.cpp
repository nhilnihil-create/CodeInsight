#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

signed main() {
    int A, B, C;

    cin >> A >> B >> C;
    int ans = 0;

    int tmpA, tmpB, tmpC;

    T tuple = make_tuple(A, B, C);
    map<T, bool> mp;
    mp[tuple] = true;

    while((A % 2 == 0) && (B % 2 == 0) && (C % 2 == 0)) {
        tmpA = (B + C) / 2;
        tmpB = (A + C) / 2;
        tmpC = (A + B) / 2;

        ans += 1;
        debug(ans);
        debug(A);
        debug(B);
        debug(C);
        hyphen();

        A = tmpA;
        B = tmpB;
        C = tmpC;

        tuple = make_tuple(A, B, C);
        if (mp.count(tuple) == 1) {
            cout << "-1" << endl;
            return 0;
        } else {
            mp[tuple] = true;
        }
    }

    cout << ans << endl;
}
