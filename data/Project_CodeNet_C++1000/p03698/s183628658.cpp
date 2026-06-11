#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string S;
    cin >> S;

    map<char, int> letters;

    bool isDuplicated = false;
    rep(i, S.size()) {
        if(letters.count(S.at(i)) == 1) { // 2回目
            isDuplicated = true;
        } else {
            letters[S.at(i)] = 1;
        }
    }

    string ans = isDuplicated ? "no" : "yes";

    cout << ans << endl;

    return 0;
}