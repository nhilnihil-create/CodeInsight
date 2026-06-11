#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;

ll comb(ll n, ll k){
    ll ret = 1;
    for(ll i = 0; i < k; ++i){
        ret *= (n - i);
        ret /= (i + 1);
    }
    return ret;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());

    ll total = 0;
    for(int i = 0; i < a; ++i){
        total += v.at(n - 1 - i);
    }
    printf("%.8f\n", (double)total / a);

    if(n == a){
        cout << 1 << endl;
        return 0;
    }

    const ll minv = v.at(n - a);
    if(v.at(n - a - 1) < minv){
        cout << 1 << endl;
        return 0;
    }

    const ll idx1 = lower_bound(v.begin(), v.end(), minv) - v.begin();
    const ll idx2 = upper_bound(v.begin(), v.end(), minv) - v.begin() - 1;
    if(v.back() > minv){
        const ll k = idx2 - (n - a) + 1;
        cout << comb(idx2 - idx1 + 1, k) << endl;
        return 0;
    }else{
        ll ans = 0;
        for(ll i = a; i <= min(b, idx2 - idx1 + 1LL); ++i){
            ans += comb(idx2 - idx1 + 1LL, i);
        }
        cout << ans << endl;
        return 0;
    }
}
