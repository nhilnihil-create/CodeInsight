#include <bits/stdc++.h>
using namespace std;

int main() {
    int l[210];
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; i++) {
        cin >> l[i];
    }
    sort(l,l+2*n);
    int ans = 0;
    for (int i = 0; i < n * 2; i += 2) {
        ans += l[i];
    }
    cout << ans << endl;
    return 0;
}