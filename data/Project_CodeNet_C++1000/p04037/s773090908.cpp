#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    rep(i, 1, n) {
        if (i + 1 > a[i + 1]) {
            int j = 0;
            while (a[j + i + 1] == i) ++j;
            puts((((a[i] - i) & 1) || (j & 1)) ? "First" : "Second");
            break;
        }
    }
    return 0;
}