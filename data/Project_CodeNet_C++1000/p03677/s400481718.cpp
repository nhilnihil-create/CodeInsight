#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

int n, m;
int A[100001];
llong M[200002];
llong B[200002];
llong ans[100001];

void add(int p, int x) {
    int c = (x - p + m) % m;
    M[x + m + 1 - c] -= 1;
    M[x + m + 1] += 1;
    B[x + m + 1 - c] += x + m + 1;
    B[x + m + 1] -= x + m + 1;

    B[x + 1] += c;
    B[x + m + 1 - c] -= c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int p;
    cin >> p;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        add(p, x);
        p = x;
    }
    for (int i = 1; i <= m + m; ++i) {
        M[i] += M[i - 1];
        B[i] += B[i - 1];
        ans[i > m ? i - m : i] += M[i] * i + B[i];
    }
    llong ret = ans[1];
    for (int i = 2; i <= m; ++i) ret = min(ret, ans[i]);
    printf("%lld\n", ret);
    return 0;
}