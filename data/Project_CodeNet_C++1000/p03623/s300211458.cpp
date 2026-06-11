#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {

    int x, a, b;
    cin >> x >> a >> b;
    if (abs(x - a) > abs(x - b))
        cout << 'B' << endl;
    else
        cout << 'A' << endl;
    return 0;
}