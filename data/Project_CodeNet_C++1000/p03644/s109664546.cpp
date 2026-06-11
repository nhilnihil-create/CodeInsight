#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; pow(2, i) <= n; i++) {
        ans = pow(2, i);
    }

    cout << ans << endl;
    return 0;
}
