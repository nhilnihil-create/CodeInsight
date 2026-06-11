#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

// 後ろから解く
// Greedy
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    rep(i, 4) reverse(divide[i].begin(), divide[i].end());

    bool can = true;
    for (int i=0; i<s.size(); ) {
        bool can2 = false;
        rep(j, 4) {
            string d = divide[j];
            if (s.substr(i, d.size()) == d) {
                can2 = true;
                i += d.size();
            }
        }
        if (!can2) {
            can = false;
            break;
        }
    }
    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}