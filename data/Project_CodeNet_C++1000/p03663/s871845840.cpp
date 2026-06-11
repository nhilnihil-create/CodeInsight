#include <bits/stdc++.h>
using namespace std;
using Int = long long;
bool query(Int n)
{
    char ch;
    cout << "? " << n << endl;
    cin >> ch;
    return ch == 'Y';
}
Int solve(function<bool(Int)> query)
{
    Int ng = 999999999, ok = 9999999999, mid;
    while (abs(ng - ok) > 1) {
        mid = (ng + ok) / 2;
        (query(mid * 10) ? ok : ng) = mid;
    }
    if (ok != 1000000000) {
        Int val = 1;
        for (int i = 0; i < 10; i++) {
            if (!query(val)) {
                return stoll(to_string(ok).substr(0, i));
            }
            val *= 10;
        }
    } else {
        Int val = 9;
        for (int i = 0; i < 10; i++) {
            if (query(val)) {
                return stoll(to_string(ok).substr(0, i+1));
            }
            val = val * 10 + 9;
        }
        return 1;
    }
    return -1;
}
int main()
{
    Int val = solve(query);
    cout << "! " << val << endl;
    return 0;
}
