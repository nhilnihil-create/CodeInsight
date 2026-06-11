#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll x, a, b;
    cin >> x >> a >> b;

    if (a >= b)
        cout << "delicious" << endl;
    else if (x >= b - a)
        cout << "safe" << endl;
    else
        cout << "dangerous" << endl;
    return 0;
}
