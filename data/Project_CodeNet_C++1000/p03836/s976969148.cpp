#include <bits/stdc++.h>
using namespace std;


void solve () {
    int x, y, tx, ty;
    cin >> x >> y >> tx >> ty;
    for (int i = 0; i < abs(x - tx); i++) {
        cout << "R";
    }
    for (int i = 0; i < abs(y - ty); i++) {
        cout << "U";
    }
    for (int i = 0; i < abs(x - tx); i++) {
        cout << "L";
    }
    for (int i = 0; i < abs(y - ty) + 1; i++) {
        cout << "D";
    }
    for (int i = 0; i < abs(x - tx) + 1; i++) {
        cout << "R";
    }
    for (int i = 0; i < abs(y - ty) + 1; i++) {
        cout << "U";
    }
    cout << "L";
    cout << "U";
    for (int i = 0; i < abs(x - tx) + 1; i++) {
        cout << "L";
    }
    for (int i = 0; i < abs(y - ty) + 1; i++) {
        cout << "D";
    }
    cout << "R";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
