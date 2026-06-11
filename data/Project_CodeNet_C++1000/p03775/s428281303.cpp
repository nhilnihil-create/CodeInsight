#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}
int main() {
    ll n;
    cin >> n;
    auto div = divisor(n);
    int ans = INT_MAX;
    for(auto e : div) {
        int a = to_string(e).size();
        int b = to_string(n / e).size();
        ans = min(ans, max(a, b));
    }
    cout << ans << endl;
}