#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

ll nck(ll n, ll k){
    ll ret = 1;
    rep(i, k){
        ret *= (n - i);
        ret /= (i + 1);
    }
    return ret;
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    int o = 0;
    int e = 0;
    rep(i, n){
        if(a[i] % 2 == 0)e++;
        else o++;
    }

    if(p == 1){
        ll odd = 0;
        rep(i, (o+1)/2){
            odd += nck(o, i*2+1);
        }
        ll even = 0;
        rep(i, e+1){
            even += nck(e, i);
        }
        ll ans = odd * even;
        cout << ans << endl;
    }else{
        ll odd = 0;
        rep(i, o/2+1){
            odd += nck(o, i*2);
        }
        ll even = 0;
        rep(i, e+1){
            even += nck(e, i);
        }
        cout << odd * even << endl;
    }
    
}