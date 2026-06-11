#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long A, B, C; cin >> A >> B >> C;
    long long ans = 0;
    if (A % 2 && B % 2 && C % 2) {
        ans = min({(A % 2) * B * C, A * (B % 2) * C, A * B * (C % 2)});
    }
    cout << ans << endl;
}