#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll N;
ll x[100050];

int main() {
    //cout.precision(10);
    cin >> N;
    ll out = 0;
    ll ans = 1;
    for(ll i = 1; i <= N; i++) {
        cin >> x[i];
        if((i - out - 1) * 2 >= x[i]) {
            ans = ans * (i - out) % mod;
            out++;
        }
    }
    for(ll i = out; i < N; i++) {
        ans = ans * (N - i)% mod;
    }
    cout << ans << endl;
    return 0;
}
