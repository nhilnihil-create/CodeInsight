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

    if(a & 1 && b & 1 && c & 1){
        cout << min({a * b, b * c, a * c}) << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}
