#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

ll f(ll a) {
    ll aa = a, cou = 0;
    while(aa > 0) {
        cou++;
        aa /= 10; 
    }
    return cou;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 1e9;

    for(ll a = 1; a * a <= n; a++) {
        if(n%a != 0) continue;
        ll b = n/a;
        ll k = max(f(a), f(b));
        ans = min(ans, k);
    }

    cout << ans << endl;

    return 0;
}