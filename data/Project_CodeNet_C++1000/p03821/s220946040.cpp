#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n)cin >> a[i] >> b[i];
    ll cnt = 0;
    for(int i = n-1; i >= 0; i--){
        (a[i] += cnt) %= b[i];
        if(a[i] > 0)cnt += b[i] - a[i];
    }
    cout << cnt << endl;
}