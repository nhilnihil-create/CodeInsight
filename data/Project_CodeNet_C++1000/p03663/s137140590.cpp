#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool ask(ll x) {
    cout << "? " << x << endl;
    string ans;
    cin >> ans;
    return ans == "Y";
}

int main() {
#ifdef __APPLE__
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    ll tl = 0, tr = 1e9 + 1;
    while (tr - tl > 1) {
        ll tm = (tl + tr) / 2;
        ll x = tm;
        while (x <= (ll)1e9)
            x *= 10;
        if (ask(x)) {
            tr = tm;
        } else {
            tl = tm;
        }
    }
    ll v = tr;
    while (v % 10 == 0) {
        v /= 10;
    }
    ll x = 0;
    if (v == 1) { 
        ll tv = v;
        while (tv) {
            tv /= 10;
            x = x * 10 + 9;
        }
        while (!ask(x) && x <= (ll)1e9) {
            v *= 10;
            x = x * 10 + 9;
        }
        cout << "! " << v << endl;
    } else {
        x = 1;
        ll tv = v;
        while (tv) {
            tv /= 10;
            x *= 10;
        }
        x *= 10;
        while (ask(x) && x <= (ll)1e9) {
            v *= 10;
            x *= 10;
        }
        cout << "! " << v << endl;
    }
    return 0;
}