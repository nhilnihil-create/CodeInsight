#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

bool ask(ll x) {
    cout << "? " << x << endl;
    string ans;
    cin >> ans;
    return ans[0] == 'Y' || ans[0] == 'y';
}

void answer(ll x) {
    cout << "! " << x << endl;
}

int main() {
    ll po = 1;
    int size = -1;
    for(int i = 0; i <= 10; i++) {
        if(!ask(po)) {
            size = i;
            break;
        }
        po *= 10;
    }
    if(size > 0) {
        ll l = po / 10, r = po - 1;
        while(r - l > 1) {
            ll m = r + l >> 1;
            bool res = ask(m * 10);
            if(res) {
                r = m;
            } else {
                l = m;
            }
        }
        if(ask(l * 10)) {
            answer(l);
        } else {
            answer(r);
        }
        return 0;
    } else {
        po = 1;
        for(int i = 0; i <= 10; i++) {
            if(ask(po * 10 -1)) {
                answer(po);
                return 0;
            }
            po *= 10;
        }
    }
    return 0;
}