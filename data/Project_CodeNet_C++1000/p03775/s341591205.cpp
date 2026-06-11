#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

ll size(ll x) {
    int cou = 0;
    while(x > 0) {
        x /= 10;
        cou++;
    }

    return cou;
}

int main(){
    ll n;
    cin >> n;

    int ans = size(n);

    for(ll i = 1LL ;i * i <= n; i++) {
        if(n%i != 0) continue;

        ll b = n / i;

        int now = max(size(i), size(b));

        ans = min(ans, now);
    }

    cout << ans << endl;

    return 0;
}