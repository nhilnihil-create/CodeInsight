#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    string s; cin >> s;

    map<char, int> mp;
    for (int i = 0; i < s.length(); ++i) {
        mp[s[i]]++;
    }

    if ((mp['N'] > 0 && mp['S'] == 0) || (mp['S'] > 0 && mp['N'] == 0)) {
        puts("No");
        return 0;
    }

    if ((mp['W'] > 0 && mp['E'] == 0) || (mp['E'] > 0 && mp['W'] == 0)) {
        puts("No");
        return 0;
    }

    puts("Yes");
}