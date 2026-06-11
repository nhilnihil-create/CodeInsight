#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;

    string s;
    cin >> s;
    int maxv = 0, cur = 0;
    for (auto ch : s) {
        if (ch == 'I') {
            cur++;
        } else {
            cur--;
        }
        maxv = max(maxv, cur);
    }
    cout << maxv << endl;
}