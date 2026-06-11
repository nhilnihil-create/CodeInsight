#include <bits/stdc++.h>

using namespace std;


int main() {
    string S;
    cin >> S;
    auto sample = "CODEFESTIVAL2016";

    int ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] != sample[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}