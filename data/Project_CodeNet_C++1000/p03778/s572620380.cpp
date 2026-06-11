#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int w, a, b;
    cin >> w >> a >> b;

    int ans = max({b - (a + w), a - (b + w), 0});

    cout << ans << endl;
    return 0;
}
