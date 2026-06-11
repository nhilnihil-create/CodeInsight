/*
    A - Children and Candies (ABC Edit)
    https://atcoder.jp/contests/abc043/tasks/abc043_a
*/

#include <iostream>

using namespace std;

#define ll long long
#define forn(i, s, n) for (int i = s; i < n; i++)
#define whilen(val, n) while(n-- && cin >> val)
#define r_1(v) cin >> v
#define r_2(v1, v2) cin >> v1 >> v2

int main() {
    int n;
    r_1(n);
    cout << (n * (n + 1)) / 2;
    return 0;
}