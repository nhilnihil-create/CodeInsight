#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int H, W; cin >> H >> W;
    int count[26] = {};
    REP(i, 0, H) {
        string s; cin >> s;
        for (auto c : s) count[c - 'a']++;
    }

    int center = 0, odd = 0;
    REP(i, 0, 26) {
        if (count[i] % 2 == 1) odd++;
        center += count[i] % 4;
    }

    if (odd > 1) {
        cout << "No" << endl;
        return 0;
    }

    int center_line = ((H % 2 == 0) ? 0 : W) + ((W % 2 == 0) ? 0 : H) - ((H % 2 == 1 && W % 2 == 1) ? 1 : 0);
    if (center == center_line) {
        cout << "Yes" << endl;
    } else if (center < center_line && (center - center_line) % 4 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}