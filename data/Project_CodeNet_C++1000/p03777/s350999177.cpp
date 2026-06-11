#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string a, b;
    cin >> a >> b;
    if (a == "H") {
        if (b == "H")
            cout << "H";
        else
            cout << "D";
    } else {
        if (b == "H")
            cout << "D";
        else
            cout << "H";
    }
    cout << endl;
}

