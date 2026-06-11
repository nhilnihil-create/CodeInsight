#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    string S;
    cin >> S;
    int len = S.size();

    ll ans = 0;
    for (int i = 0; i < (1 << (len - 1)); ++i) {
        ll tmp = S[0] - '0';
        for (int j = 0; j < len - 1; ++j) {
            if (i & (1 << j)) {
                ans += tmp;
                tmp = 0;
            }
            tmp = tmp * 10 + S[j + 1] - '0';
        }
        ans += tmp;
    }

    cout << ans << endl;
    return 0;
}
