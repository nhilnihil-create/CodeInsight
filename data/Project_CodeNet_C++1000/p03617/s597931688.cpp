#include <bits/stdc++.h>
using namespace std;
#define P pair
using ll = long long;
const int MOD = 1e9 + 7;

int main()
 {
    ll q, h, s, d;
    cin >> q >> h >> s >> d;
    ll n; cin >> n;
    h = min(2 * q, h);
    s = min(2 * h, s);
    if(2 * s <= d){
        cout << min(2 * min(2 * q, h), s) * n << endl;
    }else{
        cout << (n / 2) * min({8 * q, 4 * h, 2 * s, d}) + (n % 2) * min({4 * q, 2 * h, s}) << endl;
    }
    return 0;
}
