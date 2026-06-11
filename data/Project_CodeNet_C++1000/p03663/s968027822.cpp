#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int now = 1000000000, cnt = 10;
    int pow10[20];
    pow10[0] = 1; for (int i = 1; i <= 13; ++i) pow10[i] = pow10[i - 1] * 10;

    while(now) {
        cout << "? " << now << '\n';
        cout.flush();
        char c; cin >> c;
        if(c == 'Y') break;
        now /= 10; cnt --;
    }

    if(cnt == 10) {
        now = 1;
        while(1) {
            cout << "? " << now + 1 << '\n';
            cout.flush();
            char c; cin >> c;
            if(c == 'Y') break;
            now *= 10;
            if(now == 10000000000) break;
        }
        cout << "! " << now << '\n';
        cout.flush();
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        int l = (i == 1 ? 1 : 0), r = 9;
        while(l < r) {
            int mid = l + r >> 1;
            int rem = ans + mid * pow10[cnt - i + 1] + pow10[cnt - i + 1] - 1;
            cout << "? " << rem << '\n';
            cout.flush();
            char c; cin >> c;
            if(c == 'Y') r = mid;
            else l = mid + 1;
        }
        ans += l * pow10[cnt - i + 1];
    }

    cout << "! " << ans / 10 << '\n';
    cout.flush();

    return 0;
}
