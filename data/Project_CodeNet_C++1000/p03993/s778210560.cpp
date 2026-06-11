#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        int input;
        cin >> input;
        a.at(i) = input - 1;
    }

    int cnt = 0;
    rep(idx, n) {
        // rabbit i loves a.at(idx)
        int i = a.at(idx);

        // rabbit j loves a.at(idx)
        int j = a.at(i);
        if (idx == j && i < j)
            cnt++;
    }
    cout << cnt << endl;
}
