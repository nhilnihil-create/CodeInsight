#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mx = 1000006;
ll sam[mx], pic[mx];

int main() {
    ll n, m;
    cin >> n >> m;

    vector<bool>s(200010, false);
    vector<bool>t(200010, false);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;

        if(a == 1) {
            s[b] = true;
        }

        if(b == n) {
            t[a] = true;
        }
    }

    for (ll i = 0; i < 200010; i++) {
        if(s[i] && t[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
