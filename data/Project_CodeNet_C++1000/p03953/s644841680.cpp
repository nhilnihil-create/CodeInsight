#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define pb push_back
#define sz(v) ((li)(v).size())
#define bgn(v) ((v).begin())
#define eend(v) ((v).end())
#define allof(v) (v).begin(), (v).end()
#define dodp(v, n) memset(v, (li)n, sizeof(v))
#define bit(n) (1ll << (li)(n))
#define mp(a, b) make_pair(a, b)
#define rin rep(i, n)
#define EPS 1e-12
#define ETOL 1e-8
#define MOD 1000000007
typedef pair<li, li> PI;

#define INF bit(60)

#define DBGP 1

#define idp if (DBGP)
#define F first
#define S second
#define p2(a, b) idp cout << a << "\t" << b << endl
#define p3(a, b, c) idp cout << a << "\t" << b << "\t" << c << endl
#define p4(a, b, c, d) idp cout << a << "\t" << b << "\t" << c << "\t" << d << endl
#define p5(a, b, c, d, e) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl
#define p6(a, b, c, d, e, f) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << endl
#define p7(a, b, c, d, e, f, g) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << endl
#define p8(a, b, c, d, e, f, g, h) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << endl
#define p9(a, b, c, d, e, f, g, h, i) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << endl
#define p10(a, b, c, d, e, f, g, h, i, j) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << endl
#define foreach(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define p2p(x) idp p2((x).F, (x).S)
#define dump(x, n)                         \
    idp                                    \
    {                                      \
        rep(i, n) { cout << x[i] << " "; } \
        puts("");                          \
    }
#define dump2(x, n)                                                     \
    idp                                                                 \
    {                                                                   \
        rep(i, n) { cout << "[" << x[i].F << " , " << x[i].S << "] "; } \
        puts("");                                                       \
    }
#define dumpi(x)                  \
    idp                           \
    {                             \
        foreach (it, x)           \
        {                         \
            cout << (*it) << " "; \
        }                         \
        puts("");                 \
    }
#define dumpi2(x)                                               \
    idp                                                         \
    {                                                           \
        foreach (it, x)                                         \
        {                                                       \
            cout << "[" << (it)->F << " , " << (it)->S << "] "; \
        }                                                       \
        puts("");                                               \
    }

#define read2d(a, w, h) rep(i, h) rep(j, w) cin >> a[i][j]
#define dump2d(a, w, h)                   \
    rep(i, h)                             \
    {                                     \
        rep(j, w) cout << a[i][j] << " "; \
        puts("");                         \
    }

typedef pair<li, li> PI;

li n;
li x[100100];
li dx[100100];
li dx2[100100];
li m, k;
li a[100100];

inline vector<li> perm_njo(const vector<li>& perm, li e) {
    if (e == 1) {
        return perm;
    }
    vector<li> perm_2jo = perm;
    rep(i, sz(perm)) {
        perm_2jo[i] = perm[perm[i]];
    }
    if (e % 2 == 0) {
        return perm_njo(perm_2jo, e / 2);
    } else {
        auto perm_atoippo = perm_njo(perm_2jo, e / 2);
        vector<li> res = perm;
        rep(i, sz(perm))res[i] = perm[perm_atoippo[i]];
        return res;
    }
}

int main(void)
{
    cin >> n;
    rin{
        cin >> x[i];
    }
    cin >> m >> k;
    rep(i, m) {
        cin >> a[i];
        a[i]--;
    }

    rep(i, n - 1) {
        dx[i] = x[i + 1] - x[i];
    }

    vector<li> perm_orig(n - 1);
    rep(i, n - 1) {
        perm_orig[i] = i;
    }
    rep(i, m) {
        swap(perm_orig[a[i] - 1], perm_orig[a[i]]);
    }

    auto res = perm_njo(perm_orig, k);
    rep(i, n - 1) {
        dx2[i] = dx[res[i]];
    }
    cout << x[0] << endl;
    li now = x[0];
    rep(i, n - 1) {
        now += dx2[i];
        cout << now << endl;
    }


    return 0;
}