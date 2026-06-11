#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int a[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[n - 1] - a[0] > 1) {
        printf("No\n");
    } else if (a[n - 1] == a[0]) {
        if (n >= a[0] * 2 || n == a[0] + 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else if (a[n - 1] == a[0] + 1) {
        int sin = lower_bound(a, a + n, a[n - 1]) - a;
        int multi = a[n - 1] - sin;
        if (multi > 0 && sin + multi * 2 <= n) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
