#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    ll a, b, c; cin >> a >> b >> c;

    ll cnt = 0;
    if(a & 1 || b & 1 || c & 1){
        cout << cnt << endl;
        return 0;
    }
    while(1){
        ll x = a / 2;
        ll y = b / 2;
        ll z = c / 2;
        a += y;
        a += z;
        b += x;
        b += z;
        c += x;
        c += y;
        cnt++;

        if(a & 1 || b & 1 || c & 1){
            cout << cnt << endl;
            return 0;
        }
        if(a == b && b == c){
            cout << -1 << endl;
            return 0;
        }
    }

    return 0;
}
