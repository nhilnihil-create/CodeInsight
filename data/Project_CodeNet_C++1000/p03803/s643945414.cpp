#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int a, b;
    cin >> a >> b;
    if (a == 1)
        a = 14;
    if (b == 1)
        b = 14;

    if (a == b)
        cout << "Draw";
    else if (a > b)
        cout << "Alice";
    else
        cout << "Bob";
    cout << endl;
}