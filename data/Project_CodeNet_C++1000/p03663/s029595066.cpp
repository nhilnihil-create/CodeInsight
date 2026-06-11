#include <iostream>
#include <vector>
using namespace std;

bool ask(int64_t n)
{
    cout << "? " << n << endl
         << flush;

#if 0
    int ans = 10;
    string sn = to_string(n);
    string sa = to_string(ans);
    return (n <= ans && sn <= sa) || (n > ans && sn > sa);
#endif

    string rep;
    cin >> rep;
    return rep == "Y";
}

int main()
{
    cin.tie(0);

    int keta = 1;
    {
        int64_t mi = 1, ma = 9;

        int fst = -1, lst = -1;

        for (int i = 1; i <= 10; i++) {
            bool bmi = ask(mi);
            bool bma = ask(ma);

            if (bmi && bma) {
                if (fst == -1) {
                    fst = i;
                }
                lst = i;
            }

            mi = mi * 10;
            ma = ma * 10 + 9;
        }

        if (fst == 1) {
            if (lst == 10) {
                keta = fst;
            } else {
                keta = lst;
            }
        } else {
            keta = fst;
        }
    }

    int64_t lo = 1, hi = 10;
    for (int i = 1; i < keta; i++) {
        lo *= 10;
        hi *= 10;
    }

    while (hi - lo > 1) {
        int64_t mi = (lo + hi) / 2;

        if (!ask(mi * 10)) {
            lo = mi;
        } else {
            hi = mi;
        }
    }

    cout << "! " << (ask(lo * 10) ? lo : lo + 1) << endl
         << flush;

    return 0;
}
