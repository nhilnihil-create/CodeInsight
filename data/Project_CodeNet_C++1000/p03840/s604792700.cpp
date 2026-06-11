#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
  
typedef long long ll;
const int N = 15;
const ll mod = 1e9 + 7;

int main()
{
    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    cout << max(a / 2 * 2 + b + d / 2 * 2 + e / 2 * 2, ((a > 0) && (d > 0) && (e > 0)) * (3 + (a - 1) / 2 * 2 + b + (d - 1) / 2 * 2 + (e - 1) / 2 * 2)) << endl;
    return 0;
}