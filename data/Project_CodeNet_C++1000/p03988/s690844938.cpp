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

    int n, d = 0;
    cin >> n;
    vector<int> a(n), cnt(n, 0);
    FOR(i, 0, n) {
        cin >> a[i];
        d = max(d, a[i]);
        ++cnt[a[i]];
    }
    int hl;
    if (d % 2) {
        hl = (d + 1) / 2;
        FOR(i, hl, d + 1) {
            cnt[i] -= 2;
            if (cnt[i] < 0) {
                cout << "Impossible" << "\n";
                return 0;
            }
        }
    } else {
        hl = d / 2;
        cnt[hl] -= 1;
        if (cnt[hl] < 0) {
            cout << "Impossible" << "\n";
            return 0;
        }
        FOR(i, hl + 1, d + 1) {
            cnt[i] -= 2;
            if (cnt[i] < 0) {
                cout << "Impossible" << "\n";
                return 0;
            }
        }
    }
    FOR(i, 1, hl + 1) {
        if (cnt[i] > 0) {
            cout << "Impossible" << "\n";
            return 0;
        }
    }
    cout << "Possible" << "\n";

    return 0;
}
