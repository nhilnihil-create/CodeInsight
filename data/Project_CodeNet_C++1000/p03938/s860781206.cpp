#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)

#define EPS 1e-12

#define DEBUG_PRINT 1
#define idp if (DEBUG_PRINT)
#define p2(a, b) idp cout << a << "\t" << b << endl
#define p3(a, b, c) idp cout << a << "\t" << b << "\t" << c << endl
#define p4(a, b, c, d) idp cout << a << "\t" << b << "\t" << c << "\t" << d << endl
#define p5(a, b, c, d, e) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl
#define p6(a, b, c, d, e, f) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << endl
#define p7(a, b, c, d, e, f, g) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << endl
#define p8(a, b, c, d, e, f, g, h) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << endl
#define p9(a, b, c, d, e, f, g, h, i) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << endl
#define p10(a, b, c, d, e, f, g, h, i, j) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << endl


typedef pair<li, li> PI;

li p[20010];
li a[20010];
li b[20010];
li n;

int main(void)
{
    cin >> n;
    rep(i, n) {
        cin >> p[i];
        p[i]--;
        a[i] = 30000 * i + 1;
        b[i] = 30000 * (n - i) + 1;
    }
    rep(i, n) {
        b[p[i]] += i;
    }

    rep(i, n) {
        cout << a[i];
        if (i < n - 1)cout << " ";
    } cout << endl;
    rep(i, n) {
        cout << b[i];
        if (i < n - 1)cout << " ";
    } cout << endl;


    return 0;
}