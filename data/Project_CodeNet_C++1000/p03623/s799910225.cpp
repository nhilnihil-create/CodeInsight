#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, a, b;
    cin >> x >> a >> b;
    if (abs(x - a) <= abs(x - b)) {
        cout << "A" << "\n";
    } else {
        cout << "B" << "\n";
    }
}







