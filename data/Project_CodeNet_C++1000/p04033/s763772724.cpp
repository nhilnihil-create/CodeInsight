#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;

    if (a <= 0 && b >= 0) {
        puts("Zero");
        return 0;
    }

    if (a > 0) {
        puts("Positive");
        return 0;
    }

    ll cnt = b - a + 1;
    if (cnt & 1) {
        puts("Negative");
    } else {
        puts("Positive");
    }
}