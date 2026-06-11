#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOE(x, a) for(auto x : a)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;


const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
ll f[N], sF[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    f[0] = f[1] = f[2] = 1;
    sF[0] = 1, sF[1] = 2, sF[2] = 3;
    FOR(i, 3, n){
        f[i] = (f[i - 1] + sF[i - 3]) % MOD;
        sF[i] = (sF[i - 1] + f[i]) % MOD;
    }

    ll ans = (f[n] + f[n - 1] * (n - 1)) % MOD;

    FOR(i, 1, n - 1)
        ans = (ans + (i + (ll) (n - 1) * (n - 1)) % MOD * f[i - 1] % MOD) % MOD;

    cout << ans;

    return 0;
}

