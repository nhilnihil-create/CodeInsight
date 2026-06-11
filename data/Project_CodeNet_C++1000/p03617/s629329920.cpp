#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll q, h, s, d;
    cin >> q >> h >> s >> d;
    ll n;
    cin >> n;
    ll ans = 0;
    ll mn = min({8*q, 4*h, 2*s, d});
    if(mn == 8*q){
        cout << n * q * 4 << endl;
    }else if(mn == 4 * h){
        cout << n * h * 2 << endl;
    }else if(mn == 2 * s){
        cout << n * s << endl;
    }else{
        ll ans = n / 2 * d;
        if(n % 2 == 1){
            ll mn = min({4*q, 2*h, s});
            ans += mn;
        }
        cout << ans << endl;
    }
    
}