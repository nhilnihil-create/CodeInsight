#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> prev(26, -1);
    vector<int> len(26);
    REP(i, s.size()) {
        int c = s[i] - 'a';
        len[c] = max(len[c], i - prev[c] - 1);
        prev[c] = i;
    }
    REP(c, 26) {
        len[c] = max(len[c], (int) s.size() - prev[c] - 1);
    }
    cout << *min_element(ALL(len)) << endl;
}