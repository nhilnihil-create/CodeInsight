#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll N;
ll dpZERO[1005000];
ll sumdpZERO[1005000];
int main() {
    //cout.precision(10);
    cin >> N;
    dpZERO[0] = 1;
    dpZERO[1] = 1;
    dpZERO[2] = 1;
    sumdpZERO[0] = 1;
    sumdpZERO[1] = 2;
    sumdpZERO[2] = 3;
    for(int i = 3; i <= N; i++) {
        dpZERO[i] = (sumdpZERO[i - 1] - dpZERO[i - 2] + mod) % mod;
        sumdpZERO[i] = (sumdpZERO[i - 1] + dpZERO[i]) % mod;
        //cout << i << " " << dpZERO[i] << endl;
    }
    ll ans = 0;
    for(ll i = 0; i <= N - 2; i++) {
        ll now = dpZERO[i] * (N - 1) % mod;
        now = (now * (N - 1)) % mod;
        ans = (ans + now) % mod;
        ll hoge = min(i + 2, N - 1) * dpZERO[i] % mod;
        ans = (ans + hoge) % mod;
        //cout << i << " " << ans << endl;
    }
    //cout << endl;
    ans = (ans + dpZERO[N - 1] * (N)) % mod;
    //ans = (ans + dpZERO[N]) % mod;
    cout << ans << endl;
    return 0;
}
