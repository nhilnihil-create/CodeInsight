/*
    C - Be Together
    https://atcoder.jp/contests/abc043/tasks/arc059_a
*/

#include <iostream>

using namespace std;

#define ll long long
#define forn(i, s, n) for (int i = s; i < n; i++)
#define whilen(val, n) while(n-- && cin >> val)
#define r_1(v) cin >> v
#define r_2(v1, v2) cin >> v1 >> v2

int main() {
    int n, x, ns[101];
    r_1(n);
    int sum = 0;
    forn(i, 0, n) {
        r_1(x);
        ns[i] = x;
    }
    int min = 0;
    forn(i, -100, 101) {
        int result = 0;
        forn(j, 0, n) {
            if (i != ns[j]) result += ((ns[j] - i) * (ns[j] - i));
        }
        if (i == -100) min = result;
        else {
            if (min > result) min = result;
        }
    }
    cout << min;
    return 0;
}