#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n = 0;
    cin >> n;
    vector<ll> a(n,0);
    for(ll i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    for(int i = 0; i < n; i++) {
        if(n - 1 - 2*i >= 0) {
            cout << a.at(n - 1 - 2*i);
        } else {
            cout << a.at(2*i - n);
        }
        if(i != n - 1) {
            cout << ' ' << endl;
        }
    }
    cout << endl;


    return 0;
}