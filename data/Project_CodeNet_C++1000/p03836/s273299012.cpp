#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(), v.end()
#define dcout cout << fixed << setprecision(15)
#define arep(i, a) for(auto i : a)
#define F first
#define S second
#define VE vector<int>
#define pb(x) push_back(x)
#define MOD 1000000007
#define INF 10000000000
#define int long long
#define KETA(n) floor(log10(n) + 1)
using namespace std;
signed main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    rep(i, y2 - y1) {
        cout << "U";
    }
    rep(i, x2 - x1) {
        cout << "R";
    }
    rep(i, y2 - y1) {
        cout << "D";
    }
    rep(i, x2 - x1) {
        cout << "L";
    }
    cout << "L";
    rep(i, y2 - y1 + 1) {
        cout << "U";
    }
    rep(i, x2 - x1 + 1) {
        cout << "R";
    }
    cout << "DR";
    rep(i, y2 - y1 + 1) {
        cout << "D";
    }
    rep(i, x2 - x1 + 1) {
        cout << "L";
    }
    cout << "U" << endl;
    return 0;
}