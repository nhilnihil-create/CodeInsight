#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if(A == B && B == C) {
        if(A%2) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    int a, b, c;
    int ans = 0;
    while(true) {
        if(A%2 || B%2 || C%2) {
            cout << ans << endl;
            return 0;
        }
        ans++;
        a = A;
        b = B;
        c = C;
        A = b + c;
        B = a + c;
        C = a + b;
        A /= 2;
        B /= 2;
        C /= 2;
    }

    return 0;
}