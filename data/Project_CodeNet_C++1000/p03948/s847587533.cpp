#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 100010;
const int MOD = (int) 1e9 + 7;

const int INF = (int) 1e9;

int a[Maxn];
int d[Maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int minv = a[0], maxd = -INF;
    for (int i = 1; i < n; ++i) {
        d[i] = a[i] - minv;
        maxd = max(maxd, d[i]);
        minv = min(minv, a[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] == maxd) ++cnt;
    }
    cout << cnt << endl;
}
