#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string A, B, C;
    cin >> A >> B >> C;

    bool isOk = true;
    if (A.at(A.size() - 1) != B.at(0)) {
        isOk = false;
    }
    if (B.at(B.size() - 1) != C.at(0)) {
        isOk = false;
    }
    if (isOk) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}