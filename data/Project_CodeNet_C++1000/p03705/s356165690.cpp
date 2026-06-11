#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(n == 1){
        if(a == b)cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    if(a > b){
        cout << 0 << endl;
        return 0;
    }
    ll ans = (n - 1) * (b - a) + a - b + 1;
    cout << ans << endl;
    
}