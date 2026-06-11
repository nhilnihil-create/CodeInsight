#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, M; cin >> N >> M;
    vector<ll> fact(N + M + 1);
    ll ans = 0;
    for(int i = 0; i <= N + M; i++) {
        if(i == 0) fact[0] = 1;
        else {
            fact[i] = i * fact[i - 1];
            fact[i] %= mod;
        }
    }
    if(max(N, M) - min(N, M) > 1) {
        cout << ans << endl;
        return 0;
    }
    else if(N == M) {
        ans = 2 * fact[N] * fact[M] % mod;
        cout << ans << endl;
        return 0;
    }
    else {
        ans = fact[N] * fact[M];
        ans %= mod;
        cout << ans << endl;
        return 0;
    }
}