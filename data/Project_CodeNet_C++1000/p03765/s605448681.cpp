#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    string s, t;
    cin >> s >> t;

    int a[100010], b[100010];
    a[0] = b[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        a[i + 1] = (a[i] + (s[i] - 'A' + 1)) % 3;
    }
    for (int i = 0; i < t.size(); i++) {
        b[i + 1] = (b[i] + (t[i] - 'A' + 1)) % 3;
    }

    int q;
    cin >> q;
    while (q--) {
        int sl, sr, tl, tr;
        cin >> sl >> sr >> tl >> tr;
        cout << ((a[sr] - a[sl - 1] + 3) % 3 == (b[tr] - b[tl - 1] + 3) % 3 ? "YES" : "NO") << endl;
    }

}