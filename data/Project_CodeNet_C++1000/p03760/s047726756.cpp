#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string O, E;
    cin >> O >> E;

    rep(i, E.size()) {
        cout << O.at(i) << E.at(i);
    }
    if (E.size() < O.size()) {
        cout << O.at(O.size() - 1);
    }

    cout << endl;

    return 0;
}