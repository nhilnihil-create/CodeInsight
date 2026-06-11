#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int aa = -1, b = -1;

    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] != a[i+1]) {
            cnt = 0;
            continue;
        }
        if (a[i] == a[i+1]) {
            if (aa == -1) {
                aa = a[i];
                i++;
            }
            else {
                b = a[i];
                break;
            }
        }
    }
    if (aa == -1 || b == -1) cout << 0 << endl;
    else cout << (Int)aa * b << endl;
}