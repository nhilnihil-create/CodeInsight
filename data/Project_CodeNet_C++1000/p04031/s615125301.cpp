#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 1e9;
    for (int i = -100; i < 101; i++) {
        int calc = 0;
        for (int j : v) {
            calc += pow(j - i, 2);
        }
        if (calc < ans) ans = calc;
    }
    cout << ans;
}
