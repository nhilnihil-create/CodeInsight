/*
    A - Tak and Hotels (ABC Edit)
    https://atcoder.jp/contests/abc044/tasks/abc044_a
*/

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define forn(i, s, n) for (int i = s; i < n; i++)
#define whilen(val, n) while(n-- && cin >> val)
#define r_1(v) cin >> v
#define r_2(v1, v2) cin >> v1 >> v2


int main() {
    int n, k, x, y;
    r_1(n);
    r_1(k);
    r_1(x);
    r_1(y);
    if (n >= k) cout << (x * k) + (y * (n - k));
    else cout << (x * n);
}