#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B;
    cin >> A >> B;

    int ans = 0;
    if (A + B >= 24) {
        ans = A + B - 24;
    } else {
        ans = A + B;
    }

    cout << ans << endl;

    return 0;
}