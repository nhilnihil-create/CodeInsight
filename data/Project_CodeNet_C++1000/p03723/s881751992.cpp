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
    int cnt = 0;
    rep(i, 40){
        if(a%2==1 || b%2==1 || c%2==1){
            cout << cnt << endl;
            return 0;
        }
        ll d, e, f;
        d = (a + b) / 2;
        e = (b + c) / 2;
        f = (c + a) / 2;
        a = d; b = e; c = f;
        cnt++;
    }
    cout << -1 << endl;
}