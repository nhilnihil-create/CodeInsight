#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int main() {
    int N;
    string s1, s2;
    cin >> N >> s1 >> s2;

    vector<char> vt;
    for (int i = 0; i < N; i++) {
        if (s1[i] == s2[i]) {
            vt.push_back('t');
        } else {
            vt.push_back('y');
            i++;
        }
    }

    long long ans = 0;
    ans = (vt[0] == 't') ? 3 : 6;
    for (int i = 1; i < vt.size(); i++) {
        if (vt[i - 1] == 'y' && vt[i] == 'y') {
            ans *= 3;
        } else if (vt[i - 1] == 't') {
            ans *= 2;
        }
        ans = ans % MOD;
    }
    cout << ans << endl;
    return 0;
}
