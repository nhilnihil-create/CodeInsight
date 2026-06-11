#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    int cnt = 1, ans = 0;;
    for (int i=0; i<n-1; ++i) {
        if (a[i] == a[i+1]) {
            ++cnt;
        } else {
            ans += cnt & 1;
            cnt = 1;
        }
    }
    ans += cnt & 1;
    cout << ans;
}

int main() {

	solve();
    return 0;
}
