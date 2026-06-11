#include <iostream>
using namespace std;

int main() {
    long long A, B, C; cin >> A >> B >> C;
    if (A % 2 || B % 2 || C % 2) {
        cout << 0 << endl;
        return 0;
    }
    if (A == B && B == C) { 
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
        long long nowA = A, nowB = B, nowC = C;
        A = (nowB + nowC) / 2;
        B = (nowC + nowA) / 2;
        C = (nowA + nowB) / 2;
        ans++;
    }
    cout << ans << endl;
}