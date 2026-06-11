#include <bits/stdc++.h>

#define int long long

using namespace std;

int pw (int x) {
    int ans = 1;
    for (int i = 1; i <= x; i++) ans *= 10;
    return ans;
}

void solve(){
    int pos = 0;
    for (int i = 1; i <= 10; i++) {
        cout << "? " << pw(i) << endl;
        string s;
        cin >> s;

        if (s == "N") {
            pos = i;
            break;
        }
    }

    if (!pos) {
        for (int i = 0; i <= 9; i++) {
            cout << "? " << pw(i) + 1 << endl;
            string s;
            cin >> s;

            if (s == "Y") {
                cout << "! " << pw(i) << endl;
                return;
            }
        }
    }

    int l = pw(pos - 1);
    int r = pw(pos) - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid * 10 << endl;
        string s;
        cin >> s;

        if (s == "Y") r = mid - 1;
        else l = mid + 1;
    }

    cout << "!" << " " << l << endl;
    return;
}

signed main(){
    solve();
    return 0;
}