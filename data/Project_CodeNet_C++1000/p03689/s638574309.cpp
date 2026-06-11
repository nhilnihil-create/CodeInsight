#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, a, b;
    cin >> h >> w >> a >> b;
    if (h % a == 0 && w % b == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    bool swp = false;
    if (w % b == 0) {
        swp = true;
        swap(w, h);
        swap(a, b);
    }
    vector<int> s(w + 1);
    for (int i = w; i >= 0; i -= b) {
        s[i] = (w - i) / b + 1;
    }
    int cnt = 0;
    rep(i, 0, w) {
        if (s[i] != 0)
            cnt--;
        else
            s[i] = cnt;
    }
    vector<int> x(w);
    rep(i, 0, w) x[i] = s[i + 1] - s[i];
    if (!swp) {
        rep(i, 0, h) {
            rep(j, 0, w) cout << x[j] << ' ';
            cout << endl;
        }
    } else {
        rep(i, 0, w) {
            rep(j, 0, h) cout << x[i] << ' ';
            cout << endl;
        }
    }

    return 0;
}