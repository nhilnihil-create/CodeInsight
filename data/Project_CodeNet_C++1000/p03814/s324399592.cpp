#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "";
    cin >> s;
    int ans = 0, cnta = 0, cntz = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s.at(i) != 'A') {
            cnta++;
        } else {
            break;
        }
    }

    for (int i = s.length()-1; i >=0; --i) {
        if (s.at(i) != 'Z') {
            cntz++;
        }else{
            break;
        }
    }

    ans=s.length()-cnta-cntz;
    cout << ans << endl;

    return 0;
}