#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = (int)s.size();

    int cnt = 0;
    for (int i = 1; i < len; i++) {
        if (s.at(i) == 'g') cnt++;
    }
    int ans = max(0, min(len / 2, cnt) - (len - 1 - cnt));
    cout << ans << endl;
}   