#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    string S;
    cin >> S;
    vector<string> add = {"dream", "dreamer", "erase", "eraser"};
    reverse(S.begin(), S.end());
    rep(i,4) reverse(add.at(i).begin(), add.at(i).end());
    int left = 0;
    for (; left < S.size();) {
        rep(i,4) {
            bool ok = true;
            rep(j,add.at(i).size()) {
                if (add.at(i).at(j) != S.at(left + j)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                left += add.at(i).size();
                break;
            } else if (i == 3) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}

