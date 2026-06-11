#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main(void) {
    ll n;
    cin >> n;
    ll ans = inf;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i != 0) {
            continue;
        }
        ll x = n / i;
        ll count = 0;
        while (x) {
            x /= 10;
            count++;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
    return 0;
}

