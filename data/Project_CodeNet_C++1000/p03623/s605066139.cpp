#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int x, a, b;
    cin >> x >> a >> b;

    if (abs(x - a) < abs(x - b))
        cout << "A";
    else
        cout << "B";
    cout << endl;

    return 0;
}