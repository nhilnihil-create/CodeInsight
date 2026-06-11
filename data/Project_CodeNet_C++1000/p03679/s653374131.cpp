#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int X, A, B;
    cin >> X >> A >> B;

    int days = -A + B;

    if (days <= 0) {
        cout << "delicious" << endl;
    } else if (days <= X) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }

    return 0;
}