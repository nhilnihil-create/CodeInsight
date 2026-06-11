#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    const int MOD = 1000000007;

    int N;
    cin >> N;
    map<int, ll> p;

    for (int i = 1; i <= N; i++) {

        int x = i;
        for (int j = 2; j <= sqrt(N); j++) {
            if (x % j != 0) continue;
            ll ext = 0;
            while ( x % j == 0) {
                x /= j;
                ext++;
            }
            p[j] += ext;
        }
        if (x != 1) p[x]++;
    }

    ll cnt = 1;
    for (auto x : p) {
        ll y = (x.second + 1) % MOD;
        cnt *= y;
        cnt %= MOD;
    }

    cout << cnt << endl;
}