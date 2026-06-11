#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll a, b; cin >> a >> b;

    if (a <= 0 && 0 <= b) {
        puts("Zero");
        return 0;
    }

    if (a > 0) {
        puts("Positive");
        return 0;
    }

    if ((b - a) % 2 == 0) {
        puts("Negative");
        return 0;
    } else {
        puts("Positive");
        return 0;
    }
}