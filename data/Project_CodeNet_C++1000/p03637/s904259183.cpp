#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mx = 1000006;
ll sam[mx], pic[mx];

int main() {
    ll n;
    cin >> n;
    vector<ll>v;
    ll c1 = 0, c4 = 0, c2 = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if(x % 2 != 0) {
            c1++;
        }
        else if(x % 4 == 0) {
            c4++;
        }
        else if(x % 2 == 0) {
            c2++;
        }
    }

    if(c2 == 0) {
        if(c1  <= c4 + 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    else {
        if(c1 <= c4) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
