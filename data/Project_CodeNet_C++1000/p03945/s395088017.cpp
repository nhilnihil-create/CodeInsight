#include<bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i < s.length() - 1) {
            if (s[i] != s[i + 1]) cnt++;
        }
    }
    cout << cnt << endl;
}