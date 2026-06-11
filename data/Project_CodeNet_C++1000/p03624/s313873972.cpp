#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string S;
    cin >> S;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    set<char> data;
    for (char s : S) {
        data.insert(s);
    }
    string ans = "None";
    for (char alphabet : alphabets) {
        if (data.count(alphabet) == 0) {
            ans = alphabet;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}