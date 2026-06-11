#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

void ask(string s) {
    cout << "? " << s << endl;
}

bool get() {
    char c;
    cin >> c;
    return c == 'Y';
}

void append(string& s) {
    for (int i = 0; i < 9; i++) {
        s += '9';
    }
}

string ans = "";
int digit;

void checkdigit() {
    string s = "1";
    for (int i = 0; i < 10; i++) {
        ask(s);
        if (!get()) {
            digit = i;
            return;
        }
        s += '0';
    }
}

void checkdigit2() {
    string s = "";
    for (int i = 0; i < 10; i++) {
        s += '9';
    }
    for (int i = 0; i < 10; i++) {
        ask(s);
        if (!get()) {
            digit = 10 - i;
            return;
        }
        s.pop_back();
    }
}

int main() {
    checkdigit();
    if (digit == 0) {
        checkdigit2();
        ans = "1";
        for (int i = 0; i < digit; i++) {
            ans += '0';
        }
        cout << "! " << ans << endl;
        return 0;
    }
    for (int i = 0; i < digit; i++) {
        if (i == 0) {
            string t(ans);
            t += '1';
            append(t);
            ask(t);
            if (get()) {
                ans += '1';
                continue;
            }
            int l = 1, r = 9;
            while (l < r - 1) {
                int m = (l + r) / 2;
                t = string(ans);
                t += '0' + m;
                append(t);
                ask(t);
                if (get()) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ans += '0' + r;
        } else {
            string t(ans);
            t += '0';
            append(t);
            ask(t);
            if (get()) {
                ans += '0';
                continue;
            }
            int l = 0, r = 9;
            while (l < r - 1) {
                int m = (l + r) / 2;
                t = string(ans);
                t += '0' + m;
                append(t);
                ask(t);
                if (get()) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ans += '0' + r;
        }
    }
    cout << "! " << ans << endl;
}
