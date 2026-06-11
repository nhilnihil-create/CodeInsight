#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    if (a < b) {
        ans += a;
        ans += min(b, c);
    }
    else {
        ans += b;
        ans += min(a, c);
    }
    cout << ans << endl;
}