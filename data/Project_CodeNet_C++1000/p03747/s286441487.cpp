#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, l, t;
int x[100001];
int w[100001];
int s[100001];
int ans[100001];
int main() {
    scanf("%d%d%d", &n, &l, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", x + i, w + i);
    }
    int x0 = x[1];
    for (int i = n; i > 0; --i) {
        x[i] = (x[i] - x[1] + l) % l;
    }
    int md = 0;
    if (w[1] != 1) {
        md = 1;
        w[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i < n + 2 - i) {
                swap(x[i], x[n + 2 - i]);
                swap(w[i], w[n + 2 - i]);
            }
            x[i] = (l - x[i]) % l;
            w[i] ^= 3;
        }
    }
    int col = 0;
    for (int i = 1; i <= n; ++i) {
        s[i - 1] = ((x[i] + (3 - 2ll * w[i]) * t) % l + l) % l;
        if (w[i] == 1) continue;
        col += (2ll * t - x[i] + l) / l;
        col %= n;
    }
    int c = s[0];
    
    sort(s, s + n);
    int x = upper_bound(s, s + n, c) - s - 1;
    
    for (int i = 0; i < n; ++i) {
        ans[(col - x + i + n) % n] = s[i];
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", md ? (l - ans[(n - i) % n] + x0) % l : (ans[i] + x0) % l);
    }
    
	return 0;
}
