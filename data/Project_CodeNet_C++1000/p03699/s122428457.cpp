#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

bool dp[10200];

int main() {
    int N;
    cin >> N;

    int s[N], sum=0;
    rep(i, N) {
        cin >> s[i];
        sum += s[i];
    }
    sort(s, s+N);

    if (sum%10 != 0) cout << sum << endl;
    else {
        bool ok = false;
        rep(i, N) if ((sum-s[i])%10 != 0) {
            cout << sum - s[i] << endl;
            ok = true;
            break;
        }
        if (!ok) cout << 0 << endl;
    }


    return 0;
}

