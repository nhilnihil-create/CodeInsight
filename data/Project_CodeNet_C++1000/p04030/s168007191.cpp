#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    string ans = "";

    for(int i = 0; i < s.size(); i++) {
        if(s.at(i) == 'B') {
            if(ans.size() == 1) {
                ans = "";
            } else if(ans.size() > 1) {
                ans.erase(ans.end() - 1);
            }
        } else {
            ans += s.at(i);
        }
    }
    cout << ans << endl;

    return 0;
}