//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 5;
const int mod = (int) 1e9 + 7;

deque<int> d;

void construct (ll x) {
        if (x == 1) {
                return;
        }
        if (x & 1) {
                construct (x - 1);
                d.push_front (d.size () + 1);
        } else {
                construct (x >> 1);
                d.push_back (d.size () + 1);
        }
}

ll n;

inline void solve () {
        scanf ("%lld", &n); n++;
        construct (n);
        printf ("%d\n", d.size () + d.size ());
        for (int i : d) {
                printf ("%d ", i);
        }
        for (int i = 1; i <= d.size (); i++) {
                printf ("%d ", i);
        }
        puts ("");
}

int tests = 1;

int main () {
//        freopen (".in", "r", stdin);
//        freopen (".out", "w", stdout);
//        scanf ("%d", &tests);
        while (tests--) {
                solve ();
        }
        return 0;
}
