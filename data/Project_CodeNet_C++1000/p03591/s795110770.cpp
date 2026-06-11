#include <bits/stdc++.h>

using namespace std;


int main() {
    string S;
    cin >> S;

    auto ans = "No";
    if (S.find("YAKI") == 0) {
        ans = "Yes";
    }

    cout << ans << endl;
    return 0;
}