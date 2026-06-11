#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2) {
        for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << " ";
        for (int i = 1; i < n; i += 2) {
            cout << a[i];
            if (i == n - 2) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    } else {
        for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << " ";
        for (int i = 0; i < n; i += 2) {
            cout << a[i];
            if (i == n - 2) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}