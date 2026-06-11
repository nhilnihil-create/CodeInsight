#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];

int main() {
    cin >> s;
    long long ans = 1;
    for (char c : s) {
        for (int i = 0; i < 26; i++) {
            if (c ^ (i + 'a')) ans += cnt[i];
        }
        cnt[c - 'a']++;
    }
    cout << ans << endl;
    return 0;
}