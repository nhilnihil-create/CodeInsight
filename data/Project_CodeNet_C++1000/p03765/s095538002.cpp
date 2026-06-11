#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> sA(s.size() + 1, 0), sB(s.size() + 1, 0);
    vector<int> tA(t.size() + 1, 0), tB(t.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        sA[i + 1] = sA[i] + (s[i] == 'A');
        sB[i + 1] = sB[i] + (s[i] == 'B');
    }
    for (int i = 0; i < t.size(); i++) {
        tA[i + 1] = tA[i] + (t[i] == 'A');
        tB[i + 1] = tB[i] + (t[i] == 'B');
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d, cs, ct;
        cin >> a >> b >> c >> d;
        cs = sA[b] - sA[a - 1] + 2 * (sB[b] - sB[a - 1]);
        ct = tA[d] - tA[c - 1] + 2 * (tB[d] - tB[c - 1]);
        cout << ((cs - ct) % 3 == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}