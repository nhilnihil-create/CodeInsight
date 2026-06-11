#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (char c : s) {
        switch (c) {
            case '0':
                ans += "0";
                break;
            case '1':
                ans += "1";
                break;
            case 'B':
                if (!ans.empty()) ans.pop_back();
                break;
        }
    }

    cout << ans;
}
