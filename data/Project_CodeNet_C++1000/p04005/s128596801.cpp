#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if(a%2==0 || b%2==0 || c%2==0)cout << 0 << endl;
    else{
        ll ans = min({a*b, b*c, c*a});
        cout << ans << endl;
    }
    
}