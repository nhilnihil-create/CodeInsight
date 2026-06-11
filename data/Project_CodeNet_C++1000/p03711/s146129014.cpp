#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

bool issame(int x, int y, const vector<int> &group) {
    bool x_found = false;
    bool y_found = false;
    for (auto n : group) {
        if (x == n)
            x_found = true;
        if (y == n)
            y_found = true;
    }
    return x_found && y_found;
}

int main() {
    fastIO;

    vector<int> g1{1, 3, 5, 7, 8, 10, 12};
    vector<int> g2{4, 6, 9, 11};
    vector<int> g3{2};

    int x, y;
    cin >> x >> y;

    bool is_same = false;

    if (issame(x, y, g1) || issame(x, y, g2) || issame(x, y, g3))
        is_same = true;

    if (is_same)
        cout << "Yes\n";
    else
        cout << "No\n";
}
