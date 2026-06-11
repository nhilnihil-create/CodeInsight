#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    ll a, b;
    cin >> a >> b;
    if (a*b <= 0) cout << "Zero" << endl;
    else if (a > 0) cout << "Positive" << endl;
    else {
        if ((a - b) % 2 == 0) cout << "Negative" << endl;
        else cout << "Positive" << endl;
    }
    return 0;
}