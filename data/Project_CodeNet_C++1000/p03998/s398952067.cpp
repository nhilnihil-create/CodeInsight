#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int len[3], p[3];
string s[3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        len[i] = s[i].size();
    }
    int curr = 0;
    while (1) {
        if (p[curr] == len[curr]) break;
        p[curr]++;
        curr = s[curr][p[curr] - 1] - 'a';
    }
    cout << (char) ('A' + curr);
    return 0;
}
