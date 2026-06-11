#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int w, a, b;
    cin >> w >> a >> b;

    if (a == b) {
        cout << 0;
    } else if (a < b) {
        cout << max(0, b - a - w);
    } else {
        cout << max(0, a - b - w);
    }
}