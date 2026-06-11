#include <bits/stdc++.h>
using namespace std;
#define BE(x) (x).begin(), (x).end()

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1, f = 0;
    for (int i = 1; i < n; i++) {
        if (f == 0) {
            if (a[i-1] < a[i]) f = 1;
            if (a[i-1] > a[i]) f = 2;
        }
        if (f == 1) {
            if (a[i-1] > a[i]) ans++, f = 0;
        }
        if (f == 2) {
            if (a[i-1] < a[i]) ans++, f = 0;
        }
    }
    cout << ans << endl;
}