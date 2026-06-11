#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    int mustup = -1;
    for (int i = 0; i < n - 1; i++) {
        if (mustup == -1) {
            if (a[i] > a[i + 1]) {
                mustup = 0;
            }
            else if (a[i] < a[i + 1]) {
                mustup = 1;
            }
        }
        else {
            if (mustup == 1 && a[i + 1] < a[i]) {
                ans++;
                mustup = -1;
            }
            else if (mustup == 0 && a[i + 1] > a[i]) {
                ans++;
                mustup = -1;
            }
        }
    }

    cout << ans + 1 << endl;
    return 0;
}