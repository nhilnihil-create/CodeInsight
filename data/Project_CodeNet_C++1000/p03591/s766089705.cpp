#include <bits/stdc++.h>
using namespace std;

signed main() {
    string S; cin >> S;
    int N = S.size();
    if(N < 4) {
        cout << "No" << '\n';
        return 0;
    }
    cout << (S.substr(0, 4) == "YAKI" ? "Yes" : "No") << '\n';
    return 0;
}