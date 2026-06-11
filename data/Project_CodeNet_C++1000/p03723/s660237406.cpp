#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, C, ans = 0;
    cin >> A >> B >> C;
    if (A % 2 != 0 || B % 2 != 0 || C % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (A == B && B == C) {
        cout << -1 << endl;
        return 0;
    }
    while (A%2==0 && B%2==0 && C%2==0)
    {
        ans++;
        ll a, b, c;
        a = (B + C) / 2;
        b = (C + A) / 2;
        c = (A + B) / 2;
        A = a;
        B = b;
        C = c;
    }
    cout << ans << endl;
}
