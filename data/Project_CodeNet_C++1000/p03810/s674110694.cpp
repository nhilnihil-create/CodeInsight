//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 5;
const int mod = (int) 1e9 + 7;

inline void scan (int &a) {
        a = 0;
        char c = getchar ();
        while (c < 48 || c > 57) {
                c = getchar ();
        }
        while (c > 47 && c < 58) {
                a = (a << 1) + (a << 3) + c - 48;
                c = getchar ();
        }
}

int n, a[N];

int calc (int player) {
        int x = 0;
        for (int i = 1; i <= n; i++) {
                x += a[i] & 1;
        }
        x = n - x;
        if (x & 1) {
                return player;
        } else if (x + 1 < n) {
                return player ^ 1;
        } else {
                int g = 0;
                for (int i = 1; i <= n; i++) {
                        if (a[i] & 1) {
                                if (a[i] == 1) {
                                        return player ^ 1;
                                }
                                a[i]--;
                        }
                        g = __gcd (g, a[i]);
                }
                for (int i = 1; i <= n; i++) {
                        a[i] /= g;
                }
                return calc (player ^ 1);
        }
}

inline void solve () {
        scan (n);
        for (int i = 1; i <= n; i++) {
                scan (a[i]);
        }
        puts ((calc (1) & 1) ? "First" : "Second");
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
