#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int a[100005];
bool able[100005];

int main() {
    for (int i = 0; i < 100005; i++) {
        able[i] = true;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p = 2;
    LL ans = a[0] - 1;
    for (int i = 1; i < n; i++) {
        int times = (a[i] - 1) / p;
        ans += times;
        int r = a[i] - times * p;
        // printf("a[%d] = %d, r = %d, times = %d, p = %d\n", i, a[i], r, times, p);
        if (times == 0) {
            able[r] = false;
            while (!able[p]) { p++; }
        }
    }
    cout << ans << endl;
}
