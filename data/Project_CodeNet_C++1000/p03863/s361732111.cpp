#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    if (s[0] == s[s.size() - 1]) {
        if (s.size() % 2 == 0) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    } else {
        if (s.size() % 2 == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }
}