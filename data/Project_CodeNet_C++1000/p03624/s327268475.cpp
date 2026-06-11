#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    string S;
    cin >> S;
    bool alphabet[26];
    rep(i, 26) alphabet[i] = false;

    for (int i = 0; S[i] != '\0'; ++i) {
        alphabet[S[i]-'a'] = true;
    }

    rep(i, 26) {
        if (!alphabet[i]) {
            cout << char(i + 'a') << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}