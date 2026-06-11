// All Heil Fire Lord Zuko

#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 19;

int n, a[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == i) {
            ans ++;
            swap(a[i], a[i + 1]);
        }
    }
    cout << ans;
    return 0;
}

/* THINGS TO CHECK !! */

// Runtime -> Valid Bool Needed
// Overflows -> Checked
// Order is -> N^2

/* READ PROBLEM STATEMENT CAREFULLY */
