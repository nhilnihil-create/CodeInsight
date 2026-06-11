#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
string cf = "CODEFESTIVAL2016";

int main() {
    cin >> S;

    int ans = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != cf[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}
