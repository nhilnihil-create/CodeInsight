#include <bits/stdc++.h>
using namespace std;

int main() {
    long long Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    long long ans = 0;

    long long a1 = Q * 4;
    long long b1 = H * 2;
    long long c1 = S;
    long long min1l = min({a1, b1, c1});
    ans += min1l * (N % 2);

    long long a2 = Q * 8;
    long long b2 = H * 4;
    long long c2 = S * 2;
    long long d2 = D;
    long long min2l = min({a2, b2, c2, d2});
    ans += min2l * (N / 2);

    cout << ans << endl;
    return 0;
}