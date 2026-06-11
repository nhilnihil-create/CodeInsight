
#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define REPD(i,n) for(int i = (n)-1; i >= 0; --i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define double long double
typedef pair<int, int> II;
#define PI (2 * acos((double)0))
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define MS(a,x) memset(a, x, sizeof(a))
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define y0 u9cqu3jioajc

double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
int GI(int& x) { return scanf("%lld", &x); }

int n, a[100111];

bool check() {
    if (n == 1) return 1 - a[1] % 2;

    int cntEven = 0, cntOdd = 0;
    FOR(i,1,n) {
        if (a[i] % 2) ++cntOdd;
        else ++cntEven;
    }

    if (cntEven % 2 == 1) return 1;
    if (cntEven % 2 == 0 && cntOdd >= 2) return 0;

    bool ok = false;
    FOR(i,1,n) if (a[i] % 2 == 1 && a[i] > 1) {
        --a[i];
        ok = true;
        break;
    }

    if (!ok) {
        return cntEven % 2;
    }

    int g = a[1];
    FOR(i,2,n) g = __gcd(g, a[i]);
    FOR(i,1,n) a[i] /= g;

    return 1 - check();
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << (fixed) << setprecision(9);
    while (GI(n) == 1) {
        FOR(i,1,n) GI(a[i]);

        cout << (check() ? "First" : "Second") << endl;
    }
}
