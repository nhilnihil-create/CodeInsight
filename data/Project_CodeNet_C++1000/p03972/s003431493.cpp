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

/*vector<int> pr1, pr2, sz1, sz2;

int get1(int v) {
    if (pr1[v] == v)
        return v;
    else
        return pr1[v] = get1(pr1[v]);
}

int get2(int v) {
    if (pr2[v] == v)
        return v;
    else
        return pr2[v] = get2(pr2[v]);
}

void merge1(int v, int u) {
    v = get1(v);
    u = get1(u);
    if (v == u)
        return;
    if (sz1[v] > sz1[u]) {
        sz1[v] += sz1[u];
        pr1[u] = v;
    } else {
        sz1[u] += sz1[v];
        pr1[v] = u;
    }
}

void merge2(int v, int u) {
    v = get2(v);
    u = get2(u);
    if (v == u)
        return;
    if (sz2[v] > sz2[u]) {
        sz2[v] += sz2[u];
        pr2[u] = v;
    } else {
        sz2[u] += sz2[v];
        pr2[v] = u;
    }
}*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;
    cin >> w >> h;
    vector<int> p(w), q(h);
    FOR(i, 0, w)
        cin >> p[i];
    FOR(i, 0, h)
        cin >> q[i];
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    int p1 = 0, p2 = 0, cnt1 = w + 1, cnt2 = h + 1, ans = 0;
    while (p1 < w && p2 < h) {
        if (p[p1] < q[p2]) {
            ans += p[p1] * cnt2;
            --cnt1;
            ++p1;
        } else {
            ans += q[p2] * cnt1;
            --cnt2;
            ++p2;
        }
    }
    while (p1 < w) {
        ans += p[p1] * cnt2;
        --cnt1;
        ++p1;
    }
    while (p2 < h) {
        ans += q[p2] * cnt1;
        --cnt2;
        ++p2;
    }
    cout << ans << "\n";

    return 0;
}
