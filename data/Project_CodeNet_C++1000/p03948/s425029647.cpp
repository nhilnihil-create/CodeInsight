#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, t, a[100005] = {}, m = 0, x = 0, y = 0;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    m = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - m > x) x = a[i] - m, y = 1;
        else if (a[i] - m == x) y++;
        m = min(m, a[i]);
    }
    cout << y;
}
