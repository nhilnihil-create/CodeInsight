#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    string s; cin >> s;
    int t[26] = {}, c = 0, m = 0, len[200000];
    for (int i = s.size()-1; i >= 0; i--) {
        t[s[i]-'a']++;
        if (t[s[i]-'a'] == 1) c++;
        if (c == 26) { m++; fill(t, t+26, 0); c = 0; }
        len[i] = m;
    }
    fill(t, t+26, 0);
    int i = 0;
    char prev = 0;
    while (m >= 0) {
        if (prev > 0) { while (i < s.size() && s[i] != prev) i++; i++; }
        if (m > 0) while (len[i+1] == m) { t[s[i]-'a'] = 1; i++; }
        else while (i < s.size()) { t[s[i]-'a'] = 1; i++; }
        for (int j = 0; j < 26; j++) if (t[j] == 0) { prev = j + 'a'; putchar(prev); break; }
        m--;
        fill(t, t+26, 0);
    }
    cout << endl;
}
