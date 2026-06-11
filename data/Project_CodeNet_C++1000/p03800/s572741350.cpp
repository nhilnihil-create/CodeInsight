#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
#define fi first
#define se second
Int mod = 1e9+7;
Int INF = 1e18;
double EPS = 0.00000001;
//Int mod = 1e6+3;

int main() {
    Int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> t(n);
    t[0] = true;
    if (s[0] == 'o') {
        t[1] = t[n - 1] = true;
    }
    else {
        t[1] = true;
        t[n - 1] = false;
    }
    for (Int i = 2; i < n - 1; i++) {
        if (t[i - 1]) {
            if (s[i - 1] == 'o') {
                t[i] = t[i - 2];
            }
            else {
                t[i] = !t[i - 2];
            }
        }
        else {
            if (s[i - 1] == 'o') {
                t[i] = !t[i - 2];
            }
            else {
                t[i] = t[i - 2];
            }
        }
    }
    bool check = true;
    for (Int i = 0; i < n; i++) {
        if (t[i]) {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
        }
        else {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
        }
    }
    if (check) {
        for (Int i = 0; i < n; i++) cout << (t[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }
    t[0] = true;
    if (s[0] == 'o') {
        t[1] = t[n - 1] = false;
    }
    else {
        t[1] = false;
        t[n - 1] = true;
    }
    for (Int i = 2; i < n - 1; i++) {
        if (t[i - 1]) {
            if (s[i - 1] == 'o') {
                t[i] = t[i - 2];
            }
            else {
                t[i] = !t[i - 2];
            }
        }
        else {
            if (s[i - 1] == 'o') {
                t[i] = !t[i - 2];
            }
            else {
                t[i] = t[i - 2];
            }
        }
    }
    check = true;
    for (Int i = 0; i < n; i++) {
        if (t[i]) {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
        }
        else {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
        }
    }
    if (check) {
        for (Int i = 0; i < n; i++) cout << (t[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }
    t[0] = false;
    if (s[0] == 'x') {
        t[1] = t[n - 1] = true;
    }
    else {
        t[1] = true;
        t[n - 1] = false;
    }
    for (Int i = 2; i < n - 1; i++) {
        if (t[i - 1]) {
            if (s[i - 1] == 'o') {
                t[i] = t[i - 2];
            }
            else {
                t[i] = !t[i - 2];
            }
        }
        else {
            if (s[i - 1] == 'o') {
                t[i] = !t[i - 2];
            }
            else {
                t[i] = t[i - 2];
            }
        }
    }
    check = true;
    for (Int i = 0; i < n; i++) {
        if (t[i]) {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
        }
        else {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
        }
    }
    if (check) {
        for (Int i = 0; i < n; i++) cout << (t[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }
    t[0] = false;
    if (s[0] == 'x') {
        t[1] = t[n - 1] = false;
    }
    else {
        t[1] = false;
        t[n - 1] = true;
    }
    for (Int i = 2; i < n - 1; i++) {
        if (t[i - 1]) {
            if (s[i - 1] == 'o') {
                t[i] = t[i - 2];
            }
            else {
                t[i] = !t[i - 2];
            }
        }
        else {
            if (s[i - 1] == 'o') {
                t[i] = !t[i - 2];
            }
            else {
                t[i] = t[i - 2];
            }
        }
    }
    check = true;
    for (Int i = 0; i < n; i++) {
        if (t[i]) {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
        }
        else {
            if (s[i] == 'o') {
                if (t[(n + i - 1) % n] == t[(n + i + 1) % n]) check = false;
            }
            else {
                if (t[(n + i - 1) % n] != t[(n + i + 1) % n]) check = false;
            }
        }
    }
    if (check) {
        for (Int i = 0; i < n; i++) cout << (t[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }
    dump(-1);
    return 0;
}