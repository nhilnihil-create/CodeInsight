#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 1000005
using namespace std;

int n;
int a[N], b[N], c[N];

inline bool chk(int x) {
    for (int i = 1; i <= n * 2 - 1; ++i)
        c[i] = a[i] < x ? 0 : 1;
    for (int i = 1; i < n; ++i) {
        int l = n - i, r = n + i;
        if (c[l + 1] == c[l])
            return c[l];
        if (c[r - 1] == c[r])
            return c[r];
    }
    return c[1];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n * 2 - 1; ++i)
        scanf("%d", a + i), b[i] = a[i];
    sort(b + 1, b + n * 2);
    int l = 1, r = n * 2 - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (chk(b[mid])) l = mid + 1;
        else r = mid;
    }
    cout << b[l - 1] << endl;
    return 0;
}
