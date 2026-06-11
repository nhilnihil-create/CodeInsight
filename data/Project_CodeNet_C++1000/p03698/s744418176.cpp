#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    bool word[26]{false};
    for (auto ch : s) {
        if (word[ch - 'a'] == true) {
            cout << "no";
            return 0;
        }
        word[ch - 'a'] = true;
    }
    cout << "yes";
}