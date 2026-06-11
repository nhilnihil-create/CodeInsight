#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n1 = s.size(), n2 = t.size();
    vector<int> sa(n1 + 1, 0), sb(n1 + 1, 0), ta(n2 + 1, 0), tb(n2 + 1, 0);
    for (int i = 0; i < n1; i++) {
        if (s[i] == 'A') {
            sa[i + 1] = sa[i] + 1;
            sb[i + 1] = sb[i];
        } else {
            sa[i + 1] = sa[i];
            sb[i + 1] = sb[i] + 1;
        }
    }
    for (int i = 0; i < n2; i++) {
        if (t[i] == 'A') {
            ta[i + 1] = ta[i] + 1;
            tb[i + 1] = tb[i];
        } else {
            ta[i + 1] = ta[i];
            tb[i + 1] = tb[i] + 1;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int c1 = sa[b] - sa[a - 1] + 2 * (sb[b] - sb[a - 1]);
        int c2 = ta[d] - ta[c - 1] + 2 * (tb[d] - tb[c - 1]);
        // cout << c1 << " " << c2 << endl;
        if (c1 % 3 == c2 % 3) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}
