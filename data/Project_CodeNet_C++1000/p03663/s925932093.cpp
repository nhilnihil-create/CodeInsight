#include <iostream>

#define ll long long

using namespace std;

ll res = 0;

bool ask(ll a) {
    if (a == 0) return false;
    cout << "? " << a << "\n" << flush;
    char c;
    cin >> c;
    return c == 'Y';
}

int main() {
    for (int i = 0; i < 10; ++i) {
        if (i == 9) {
            res = 1e9;
            break;
        }
        if (ask(res * 10 + 9)) {
            if (i == 0 && (!ask((ll)9e9) || (!ask((ll)8e9) && ask(10)))) {
                res = 9;
            } else if (ask(res * 100)) {
                ll a = res * 10;
                while (a < (ll) 1e12) a = a * 10 + 9;
                if (ask(a)) {
                    res *= 10;
                    break;
                }
                res = res * 10 + 9;
            } else {
                int u = 0, o = 9;
                while (u < o) {
                    int m = (u + o) / 2;
                    if (ask(res * 100 + m * 10)) o = m;
                    else u = m + 1;
                }
                res = res * 10 + u;
                break;
            }
            continue;
        }
        int u = 0, o = 8;
        while (u < o) {
            int m = (u + o + 1) / 2;
            if (ask(res * 10 + m)) u = m;
            else o = m - 1;
        }
        res = res * 10 + u;
    }
    cout << "! " << res << "\n" << flush;
}
