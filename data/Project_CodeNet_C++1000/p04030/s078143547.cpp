#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    string ans;

    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '0' || s.at(i) == '1') {
            ans += s.at(i);
        }
        else {
            if (ans.size() > 0) {
                ans.pop_back();
            }
        }
    }

    cout << ans << endl;
}
