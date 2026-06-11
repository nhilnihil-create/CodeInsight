#include <iostream>
using namespace std;

int main() {
    string s, t;
    int q;
    cin >> s >> t >> q;
    int sp[s.size() + 1], tp[t.size() + 1];
    sp[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] == 'A') {
            sp[i] = sp[i - 1] + 1;
        } else {
            sp[i] = sp[i - 1] + 2;
        }
    }
    tp[0] = 0;
    for (int i = 1; i <= t.size(); i++) {
        if (t[i - 1] == 'A') {
            tp[i] = tp[i - 1] + 1;
        } else {
            tp[i] = tp[i - 1] + 2;
        }
    }
    for (int a, b, c, d; cin >> a >> b >> c >> d; ) {
        int left = sp[b] - sp[a - 1], right = tp[d] - tp[c - 1];
        if (left % 3 == right % 3) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
