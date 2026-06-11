#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a >= 0 ? a : -a;
    return gcd(b, a % b);
}
bool solve() {
    int N, K, g;
    cin >> N >> K >> g;
    int M = g;
    for (int i = 1, A; i < N; i++) {
        cin >> A;
        if (A > M) M = A;
        g = gcd(g, A);
    }
    if (K > M) return false;
    if (g == 1 || K % g == 0) return true;
    return false;
}
int main() {
    cout << (solve() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}