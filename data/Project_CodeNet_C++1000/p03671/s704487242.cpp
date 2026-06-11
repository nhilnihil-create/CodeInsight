#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = a + b + c - max({a, b, c});

    cout << ans << endl;
    return 0;
}
