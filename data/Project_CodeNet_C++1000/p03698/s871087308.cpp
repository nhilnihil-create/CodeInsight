#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string S;
    cin >> S;

    string ans = "yes";
    for (int i = 0; i < S.size(); i++) {
        for (int j = i + 1; j < S.size(); j++) {
            if (S.at(i) == S.at(j)) ans = "no";
        }
    }

    cout << ans << endl;

    return 0;
}