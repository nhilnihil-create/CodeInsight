#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int MIN = 200 * 200 * 100;
    for (int i = -100; i <= 100; i++) {
        int sum = 0;
        rep(j, n) {
            sum += (a[j] - i) * (a[j] - i);
        }
        MIN = min(sum, MIN);
    }
    cout << MIN << endl;
}