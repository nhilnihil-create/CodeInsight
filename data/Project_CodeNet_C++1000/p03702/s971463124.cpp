#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, a, b;
int H[100000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b;
    a -= b;
    for (int i = 0; i < n; ++i) cin >> H[i];
    int s = 1, e = 1e9;
    while (s < e) {
        int m = (s + e) / 2;
        llong add = 0;
        for (int i = 0; i < n; ++i) {
            add += (max(H[i] - (llong)b * m, 0ll) + a - 1) / a;
        }
        if (add <= m) e = m;
        else s = m + 1;
    }
    printf("%d\n", s);
    return 0;
}