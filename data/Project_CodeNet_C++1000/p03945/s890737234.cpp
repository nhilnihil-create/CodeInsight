#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    string S;
    cin >> S;
    int B_count = 0;
    int W_count = 0;
    char next;
    rep(i, S.size()) {
        if (i == 0) {
            if (S[0] == 'B') {
                B_count++;
                next = 'B';
            }
            else {
                W_count++;
                next = 'W';
            }
            continue;
        }
        if (S[i] == next) {
            continue;
        }
        next = S[i];
        if (next == 'B') {
            B_count++;
        }
        else {
            W_count++;
        }
    }
    cout << B_count+W_count-1 << endl;
}