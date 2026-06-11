#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    if (A == B && A == C) {
        if (A % 2 == 1) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    long long ans = 0;
    while (true) {
        if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
            cout << ans << endl;
            return 0;
        }
        long long divA = A / 2;
        long long divB = B / 2;
        long long divC = C / 2;

        A = divB + divC;
        B = divA + divC;
        C = divA + divB;
        ans++;
    }

    return 0;
}
