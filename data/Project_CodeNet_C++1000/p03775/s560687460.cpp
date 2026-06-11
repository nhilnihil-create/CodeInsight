#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll f(ll a, ll b) {
    string sa = to_string(a);
    string sb = to_string(b);
//    cerr << sa << " " << sb << endl;
    return max(sa.size(), sb.size());
}

int main(){
    ll n;
    cin >> n;
    ll ans = 1e18;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i != 0) continue;
        ans = min(ans, f(i, n/i));
    }
    cout << ans << endl;
    return 0;
}