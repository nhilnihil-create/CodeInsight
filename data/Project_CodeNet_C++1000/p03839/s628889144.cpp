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

const int Maxn = (int) 1e5 + 10;

ll sum[2][Maxn];

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum[0][i + 1] = sum[0][i] + x;
        sum[1][i + 1] = sum[1][i] + max(0, x);
    }

    ll ans = 0;
    for (int i = 0; i < n - k + 1; ++i) {
        ll score = sum[1][i] + sum[1][n] - sum[1][i + k];
        score += max(0LL, sum[0][i + k] - sum[0][i]);
        ans = max(ans, score);
    }
    cout << ans << endl;
}
