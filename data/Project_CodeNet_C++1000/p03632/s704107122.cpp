#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b <= c || d <= a)
        cout << 0;
    else if (c <= a && b <= d)
        cout << b - a;
    else if (a <= c && d <= b)
        cout << d - c;
    else if (a < c && c < b && b < d)
        cout << b - c;
    else
        cout << d - a;
}