#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(int _##i = (t), i = (f); i <  _##i; i++)
#define downto(f, t, i)  for(int _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(int _##i = (t), i = (f); i >  _##i; i--)
typedef long double ld;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
    #define debug true
    #define ln << endl
#else
    #define debug false
    #define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '

const int MOD = 1e9+7;
constexpr int T = 4;

signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    int a = 0, b = 10;
    times(T, i) {
        int k = (a + b) / 2;
        long m = 1;
        times(k, i) m *= 10;
        printf("? %lld\n", m);
        fflush(stdout);
        char c;
        scanf(" %c", &c);
        if(c == 'Y')
            a = k;
        else if(c == 'N')
            b = k;
        else
            while(b) b=b||a++;
    }
    if(debug) cout << a ln;

    if(a >= 9) {
        long d = 10;
        times(10, i) {
            printf("? %lld\n", d-1);
            fflush(stdout);
            char c;
            scanf(" %c", &c);
            if(c == 'Y') {
                printf("! %lld\n", d / 10);
                return 0;
            }
            d *= 10;
        }
    }

    long d = 1e17, e = 0;
    times(a+1, i) {
        int f = 0, g = 10;
        times(T, j) {
            int k = (f + g) / 2;
            long m = e + k * d;
            printf("? %lld\n", m);
            fflush(stdout);
            char c;
            scanf(" %c", &c);
            if(c == 'N')
                f = k;
            else if(c == 'Y')
                g = k;
            else
                while(g) g=g||f++;
        }
        e += f * d;
        d /= 10;
        if(debug) cout << e ln;
    }

    printf("! %lld\n", e / d / 10 + 1);

    return 0;
}
