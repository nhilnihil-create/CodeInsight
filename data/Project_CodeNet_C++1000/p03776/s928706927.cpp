#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

ll getC(ll n, ll r) {
    ll ans = 1;
    if (n < r || n <= 0 || r <= 0) return 0;
    for (ll i = 1; i <= r; i++) {
        ans *= n + 1 - i;
        ans /= i;
    }
    return ans;
}

int main() {

    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    rep(i,N) cin >> v[i];

    sort(v.rbegin(), v.rend());
    ll sum = 0;
    rep(i,A) sum += v[i];
    cout << fixed << setprecision(10) << ((double) sum / (double) A) << endl;

    ll ans = 0;
    int top_index = -1;
    int len = 0;

    rep(i,N) {
        if (v[i] == v[A - 1]) len++;
        if (top_index < 0 && v[i] == v[A - 1]) top_index = i;
    }

    int k = A - top_index;
    
    if (v[0] == v[A - 1]) {
        for (int i = A; i <= min(len, B); i++) ans += getC(len, i);
    } else {
        ans = getC(len, k);
    }

    cout << ans << endl;

    return 0;
}