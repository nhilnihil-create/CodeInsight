#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll>v;
    ll x;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i  = n - 1; i  >= 0; i = i - 2) {
        cout << v[i] << " ";
    }
    if (n % 2 == 0) {
         for (int i  = 0; i  < n; i = i + 2) {
        cout << v[i] << " ";
    }
    }
    else {
         for (int i  = 1; i < n; i = i + 2) {
            cout << v[i] << " ";
    }
    }
    cout << endl;
    return 0;
}
