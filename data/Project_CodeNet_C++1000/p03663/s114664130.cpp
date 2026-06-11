#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}


int ask(ll x) {
    cout << "? " << x << "\n";
    cout.flush();
    string s;
    cin >> s;
    if (s == "Y")
        return 1;
    return 0;
    /*
    cout << "? " << x << "\n";
    ll n = 12345;
    if (x <= n && to_string(x) <= to_string(n)) {
        cout << "Y\n";
        return 1;
    }
    if (x > n && to_string(x) > to_string(n)) {
        cout << "Y\n";
        return 1;
    }
    cout << "N\n";
    return 0;*/
}

int check(ll x) {
    while (x < 1e12)
        x = x * 10 + 9;
    if (ask(x))
        return 1;
    return 0;
}

int main() {
    ll x = 0;
    while (true) {
        int l = -1;
        int r = 9;
        if (x == 0)
            l = 0;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (check(x * 10 + mid))
                r = mid;
            else
                l = mid;
        }
        x = x * 10 + r;
        if (r != 9) {
            if (ask(x + 1)) {
                cout << "! " << x << "\n";
                cout.flush();
                return 0;
            }
        }
        else {
            if (!ask((x - 1) * 10)) {
                cout << "! " << x << "\n";
                cout.flush();
                return 0;
            }
        }
    }
    return 0;
}


