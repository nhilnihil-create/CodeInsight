
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

constexpr static int MOD = 1e9 + 7;
constexpr static int MAXN = 1e6;

int n;
int x[MAXN];

int solve() {
    // look at the range at which the kth pick can "go"
    int cur = 1;
    int used = 0;
    int64_t total = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] < cur) {
            total = total * (i + 1 - used) % MOD;
            used++;
        }
        else {
            cur += 2;
        }
    }
    while (used < n) {
        total = total * (n - used) % MOD;
        used++;
    }
    return (int) total;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    printf("%d\n", solve());
}
