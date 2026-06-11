#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    string S;
    cin >> S;
    if ( S.size() < 4 ) return false;
    if ( S.substr(0,4) == "YAKI") return true;
    return false;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}