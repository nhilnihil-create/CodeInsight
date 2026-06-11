#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> v;
    for (char c : s) {
        switch (c) {
            case '0':
                v.push_back('0');
                break;
            case '1':
                v.push_back('1');
                break;
            case 'B':
                if (v.size() != 0) v.pop_back();
                break;
        }
    }

    string ans;
    for (char c : v) ans += c;
    cout << ans;
}
