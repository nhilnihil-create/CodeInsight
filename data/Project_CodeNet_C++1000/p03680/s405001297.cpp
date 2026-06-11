#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<int> buttons(n);
    rep(i, n) cin >> buttons.at(i);
    int light = 1;
    int cnt = 0;
    for (size_t i = 0; i < buttons.size(); i++) {
        light = buttons.at(light - 1);
        cnt++;
        if (light == 2) {
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
}