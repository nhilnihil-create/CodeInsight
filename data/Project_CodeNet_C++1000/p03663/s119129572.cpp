#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    vector<ll> ten(12, 1);
    for(int i = 1; i < 12; ++i) {
        ten[i] = ten[i - 1] * 10LL;
    }

    int digit = 0;
    while(digit < 11) {
        cout << "? " << ten[digit] << endl;
        char res;
        cin >> res;
        if(res == 'Y') {
            digit++;
        } else {
            break;
        }
    }
    if(digit == 11) { // 1 or 10 or ... 10^n
        ll tmp = 9;
        digit = 0;
        while(digit < 11) {
            cout << "? " << tmp << endl;
            char res; cin >> res;
            if(res == 'Y') {
                break;
            }
            tmp *= 10;
            tmp += 9;
            digit++;
        }
        cout << "! " << ten[digit] << endl;
    } else {
        ll lb = ten[digit], ub = ten[digit + 1];
        while(ub - lb > 1) {
            ll m = (lb + ub) / 2;
            cout << "? " << m << endl;
            char r;
            cin >> r;
            if(r == 'Y') {
                ub = m;
            } else {
                lb = m;
            }
        }
        cout << "! " << ub / 10 << endl;
    }
}
