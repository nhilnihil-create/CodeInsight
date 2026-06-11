#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__


const int MOD = 1000000007;

ll modpow(ll a, ll n) {
    ll x = a;
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans *= x;
            ans %= MOD;
        }

        n = n>>1;
        x *= x;
        x %= MOD;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;

    vl A(N);
    rep(i, N) {
        cin >> A[i];
    }

    map<int, int> G;
    rep(i, N) {
        G[A[i]]++;
    }

    ll ans;
    // Nが奇数 => Aiは "N以下の偶数が2つづつ"と0 以外は矛盾
    // 並び順は0以外の各iにつき2通りパターン。片方を固定したら、もう片方が決まるので、2^((N-1)/2)
    if (N % 2 == 1) {
        for (auto x : G) {
            if (x.first == 0) {
                if (x.second != 1) {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                if (x.second != 2) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }

        ans = modpow(2, (N - 1) / 2);
    }
    // Nが偶数 => Aiは "N以下の奇数が2つづつ" 以外は矛盾
    // 並び順は各iにつき2通りパターンある。片方を固定したら、もう片方が決まるので、2^(N/2)
    else {
        for (auto x : G) {
            if (x.second != 2) {
                cout << 0 << endl;
                return 0;
            }
        }
        ans = modpow(2, N / 2);
    }

    cout << ans << endl;
}