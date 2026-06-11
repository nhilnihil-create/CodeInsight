#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
int main() {
    int l = 1, r = 10;
    auto check = [](int k) {
        string s = "";
        for (int i = 0; i < k; i++) s += '9';
        cout << "? " << s << endl;
        char c;
        cin >> c;
        if (c == 'Y') return 1;
        else return 0;
    };
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    int ws = r;
    auto check1 = [](int k) {
        string s = "1";
        for (int i = 1; i < k; i++) s += '0';
        cout << "? " << s << endl;
        char c;
        cin >> c;
        if (c == 'Y') return 1;
        else return 0;
    };
    l = 1, r = 11;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check1(mid)) l = mid + 1;
        else r = mid;
    }
    r--;
    if (ws == 1 && r != 10) ws = r;
    string ans = "";
    for (int i = 0; i < ws - 1; i++) {
        auto judge = [&](int k) {
            string s = ans;
            s += '0' + k;
            cout << "? " << s << endl;
            char c;
            cin >> c;
            if (c == 'Y') return 1;
            else return 0;
        };
        int l = 0, r = 10;
        if (!i) l++;
        while (l < r) {
            int mid = (l + r) / 2;
            if (judge(mid)) l = mid + 1;
            else r = mid;
        }
        ans += '0' + r - 1;
    }
    auto judge = [&](int k) {
        string s = ans;
        s += '0' + k;
        s += '0';
        cout << "? " << s << endl;
        char c;
        cin >> c;
        if (c == 'Y') return 1;
        else return 0;
    };
    l = 0, r = 9;
    if (ws == 1) l++;
    while (l < r) {
        int mid = (l + r) / 2;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    ans += '0' + r;
    cout << "! " << ans << endl;
}
