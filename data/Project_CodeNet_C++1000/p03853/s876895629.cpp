#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int h, w;
    cin >> h >> w;
    vector<string> pixels(h);
    rep(i, h) cin >> pixels[i];
    rep(i, h) rep(_, 2) cout << pixels[i] << endl;
}