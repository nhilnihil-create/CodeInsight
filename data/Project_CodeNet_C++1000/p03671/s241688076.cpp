#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ab = a + b;
    int bc = b + c;
    int ac = a + c;
    int ans = 100000;

    ans = min(ans, ab);
    ans = min(ans, bc);
    ans = min(ans, ac);

    cout << ans << endl;

    return 0;
}