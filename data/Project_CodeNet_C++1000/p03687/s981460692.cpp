#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    unordered_map<char, int> mpidx;
    int slen = s.size();
    int ans = 101;
    for (int i = 0; i < slen; i++) {
        mp[s.at(i)] = 0;
        mpidx[s.at(i)] = slen - 1 - i;
    }
    for (int i = 0; i < slen; i++) {
        int cnt = 0;
        for (int j = i-1; j >= 0; j--) {
            if (s.at(i) != s.at(j)) cnt++;
            else break;
        }
        if (mp[s.at(i)] < cnt) mp[s.at(i)] = cnt;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (mpidx[it->first] <= it->second) ans = min(ans, it->second);
        else ans = min(ans, mpidx[it->first]);
    }
    cout << ans << endl;
}