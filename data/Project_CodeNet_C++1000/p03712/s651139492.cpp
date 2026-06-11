#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int h, w;
    cin >> h >> w;
    vector<string> str(h);
    rep(i, h) cin >> str.at(i);

    rep(i, w + 2) cout << "#";
    cout << endl;
    rep(i, h) cout << "#" << str.at(i) << "#" << endl;
    rep(i, w + 2) cout << "#";
    cout << endl;
}