#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}