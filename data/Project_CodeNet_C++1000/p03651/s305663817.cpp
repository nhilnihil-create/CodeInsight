#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

ll GCD(ll a, ll b) {
    return (b > 0) ? GCD(b, a % b) : a;
}

ll LCM(ll a, ll b) {
    return a / GCD(a, b) * b;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    int g = a[0];
    int mx = 0;
    rep(i, n){
        mx = max(mx, a[i]);
        g = GCD(g, a[i]);
    }
    if(mx < k){
        cout << "IMPOSSIBLE" << endl;
    }else{
        if(k % g == 0)cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    
}