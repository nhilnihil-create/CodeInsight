#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 1)
        a += 13;
    if (b == 1)
        b += 13;
    if (a > b)
        cout << "Alice" << endl;
    else if (a == b)
        cout << "Draw" << endl;
    else
        cout << "Bob" << endl;
    return 0;
}