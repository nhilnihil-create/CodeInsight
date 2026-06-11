#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using lll = uint64_t;
using namespace std;

// TLE?
// overflow ?
int main() {
    fastIO;
    lll a, b, c;
    cin >> a >> b >> c;

    lll total = a * b * c;

    vector<lll> partial;
    partial.push_back((a / 2) * b * c);
    partial.push_back((a / 2 + 1) * b * c);

    partial.push_back((b / 2) * c * a);
    partial.push_back((b / 2 + 1) * c * a);

    partial.push_back((c / 2) * a * b);
    partial.push_back((c / 2 + 1) * a * b);

    lll min_diff = total;
    for (auto red : partial) {
        lll blue = total - red;
        lll diff = max(red, blue) - min(red, blue);
        // cout << "red = " << red << endl;
        // cout << "blue = " << blue << endl;
        // cout << "abs(red - blue) = " << diff << endl;

        min_diff = min(min_diff, diff);
    }
    cout << min_diff << endl;
}
