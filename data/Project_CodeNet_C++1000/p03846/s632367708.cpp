#include<bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
int main(void) {
    int n;
    cin >> n;
    vector<int> A(n);
    map<int, bool> already;
    for (auto &a: A) cin >> a;
    int cnt = 0;
    bool can = true;
    for (auto a : A) {
        float x = (float) (a + n - 1) / 2.0f;
        int ix = (int) x;
        bool same = 2 * ix == (n - 1);
        if (floor(x) == x) {
            if (same) {
                if (already[x]) {
                    can = false;
                    break;
                }
            } else {
                if (!already[x]) cnt++;
            }
            already[x] = true;
        } else {
            can = false;
            break;
        }
    }
    if (!can) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 1;
    for (int i = 0; i < cnt; ++i) {
        ans = ans * 2 % MOD;
    }
    cout << ans << endl;
}