#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> color{a, b, c};

    int cnt = 0;
    rep (i,4) {
        if (i == 3) break;
        if (color[i] != color[i+1]) {
            if (color[i] != color[i+2]) {
            cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}