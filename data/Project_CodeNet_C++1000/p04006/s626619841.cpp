#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iterator>
#include <fstream>
#include <math.h>

#include <random>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <list>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

#include <random>
#include <ctime>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define FOR(i, from, to) for (int i = from; i < to; i++)
#define ROF(i, from, to) for (int i = from; i > to; i--)

const long double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000000;
const ll M = 1000000007;
const ll LLINF = 1000000000000000000;
const double EPS = 1e-8;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, ans = 0, tmp, n2;
    cin >> n >> x;
    n2 = 2 * n;
    vector<int> a(n2);
    FOR(i, 0, n) {
        cin >> a[i];
        ans += a[i];
    }
    FOR(i, n, n2)
        a[i] = a[i % n];
    vector<vector<int> > prec(n2, vector<int>(n2, LLINF));
    FOR(i, 0, n2) {
        prec[i][i] = a[i];
        FOR(j, i + 1, n2)
            prec[i][j] = min(a[j], prec[i][j - 1]);
    }
    FOR(i, 1, n + 1) {
        tmp = i * x;
        FOR(j, n, n2)
            tmp += prec[j - i][j];
        ans = min(ans, tmp);
    }
    cout << ans << "\n";

    return 0;
}
