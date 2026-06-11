#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100000 + 10;
const int BIG = 1000000000LL * 1000LL;

int cnt;
int pref;
int make_num(int x) {
    int y = pref * 10 + x;
    while (y < BIG) {
        y = 10*y+9;
    }
    return y;
}

bool check(int x) {
    cout << "? " << x << endl;
    string s;
    cin >> s;
    return s == "Y";
}

int32_t main() {
    ios_base::sync_with_stdio(0);

    for (int i = 0; i <= 9; i++) {

        int p = 0, q = 9;
        if (i == 0) p = 1;

        while (p < q) {
            int s = (p+q)/2;
            cerr << "s " << s << endl;
            int n = make_num(s);
            bool r = check(n);

            if (r) {
                q = s;
            } else {
                p = s+1;
            }
        }
        pref = 10 * pref + p;

        if (pref >= 1000000000) break;
        cerr << "pref " << pref <<endl;
    }
    while (pref % 10 == 0) pref /= 10;

    int ans = pref;
    if (pref % 10 < 9) {
        if (check(pref+1)) {
            cout << "! " << pref << endl;
            return 0;
        }
    } else {
        if (!check((pref-1) * 10)) {
            cout << "! " << pref << endl;
            return 0;
        }
    }
    while (pref < BIG) {
        pref = pref * 10 + 9;
        ans *= 10;
        if (check(pref)) {
            cout << "! " << ans << endl;
            return 0;
        }
    }


    cout << "! " << pref << endl;
    return 0;
}
