#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B;
    cin >> A >> B;

    int sum = A + B;
    if (10 <= sum) {
        cout << "error" << endl;
    } else {
        cout << sum << endl;
    }
    return 0;
}