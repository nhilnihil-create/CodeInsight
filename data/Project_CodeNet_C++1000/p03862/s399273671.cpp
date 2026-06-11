#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long x, ans;
    cin >> n >> x;
    vector <long long> a(n);
    for (long long &ai: a)
        cin >> ai;
    ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i-1] > x) {
            ans += a[i] + a[i-1] - x;
            if (a[i-1] - x <= 0) {
                a[i] = - a[i-1] + x;
            } else {
                a[i-1] = x;
                a[i] = 0;
            }
        }
    }


    cout << ans;
}

int main() {

    solve();
    return 0;
}
