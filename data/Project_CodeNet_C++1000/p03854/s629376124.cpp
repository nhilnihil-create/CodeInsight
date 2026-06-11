#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> t = {"maerd", "remaerd", "esare", "resare"};
    string ans = "YES";

    reverse(s.begin(), s.end());

    int i;
    while(s.size() > 0) {
        int tmp = s.size();
        for(i = 0; i < 4; i++) {
            if (s.substr(0, t[i].size()) == t[i]) {
                s.erase(s.begin(), s.begin() + t[i].size());
            }
        }
        if (tmp == (int)s.size()) {
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
}
