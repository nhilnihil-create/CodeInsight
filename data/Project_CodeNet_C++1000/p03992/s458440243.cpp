#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        cout << s.at(i);
        if (i == 3)
            cout << " ";
    }
    cout << endl;
}