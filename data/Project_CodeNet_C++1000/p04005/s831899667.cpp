#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    if (A % 2 && B % 2 && C % 2) {
        long long ans = 2e18;
        ans = min(ans, A * B);
        ans = min(ans, B * C);
        ans = min(ans, C * A);
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
