#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string ans = "No";
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
        if ((n - i) * j + i * (m -  j) == k) ans = "Yes";
    }

    cout << ans << endl;
    return 0;
}