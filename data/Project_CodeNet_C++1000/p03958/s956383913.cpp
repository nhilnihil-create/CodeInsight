#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int k, t;
    cin >> k >> t;
    int a[t];
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }

    int m = 0;
    for (int i = 0; i < t; i++) {
        m = max(m, a[i]);
    }

    cout << max(0, m - 1 - (k - m)) << endl;;
    return 0;
}