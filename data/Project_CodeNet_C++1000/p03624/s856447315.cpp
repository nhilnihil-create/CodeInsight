#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    int alpha[26]{0};
    for (auto ch : s) alpha[ch - 'a'] = 1;
    rep(i, 26) {
        if (alpha[i] != 1) {
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }
    cout << "None\n";
}