#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B;
    cin >> A >> B;

    bool isOk = false;
    if (A % 3 == 0) {
        isOk = true;
    } else if (B % 3 == 0) {
        isOk = true;
    } else if ((A + B) % 3 == 0) {
        isOk = true;
    }
    if (isOk) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}