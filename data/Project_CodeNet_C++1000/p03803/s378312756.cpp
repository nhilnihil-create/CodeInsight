#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;
    if ((A + 12) % 14 > (B + 12) % 14) cout << "Alice" << endl;
    else if ((A + 12) % 14 < (B + 12) % 14) cout << "Bob" << endl;
    else cout << "Draw" << endl;
    return 0;
}