#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    string w1 = "dream";
    string w2 = "dreamer";
    string w3 = "erase";
    string w4 = "eraser";

    reverse(w1.begin(), w1.end());
    reverse(w2.begin(), w2.end());
    reverse(w3.begin(), w3.end());
    reverse(w4.begin(), w4.end());

    for (ll i = 0; i < S.size();) {
        if (S.substr(i, w1.size()) == w1) {
            i += w1.size();
        } else if (S.substr(i, w2.size()) == w2) {
            i += w2.size();
        } else if (S.substr(i, w3.size()) == w3) {
            i += w3.size();
        } else if (S.substr(i, w4.size()) == w4) {
            i += w4.size();
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
