#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<bool> A(26, false);
    rep(i, s.size()) { A[s[i] - 'a'] = true; }

    rep(i, 26) {
        if (!A[i]) {
            char ans = i + 'a';
            cout << ans << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    return 0;
}