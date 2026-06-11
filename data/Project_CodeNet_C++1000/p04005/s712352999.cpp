#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
        cout << 0 << endl;
    else
        cout << min(min(a * b, b * c), a * c) << endl;
    return 0;
}