#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx-sx;
    int dy = ty-sy;

    cout << string(dx,'R');
    cout << string(dy,'U');
    cout << string(dx,'L');
    cout << string(dy,'D');
    cout << string(1,'D');
    cout << string(dx+1,'R');
    cout << string(dy+1,'U');
    cout << string(1,'L');
    cout << string(1,'U');
    cout << string(dx+1,'L');
    cout << string(dy+1,'D');
    cout << string(1,'R') << '\n';
}