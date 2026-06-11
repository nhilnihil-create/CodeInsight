#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll a, b;
    cin >> a >> b;
    if(a > 0) {
        cout << "Positive" << endl;
    } else {
        if(b >= 0) {
            cout << "Zero" << endl;
        } else {
            ll temp = b - a;
            cout << (temp % 2 == 0 ? "Negative" : "Positive") << endl;
        }
    }
    return 0;
}
