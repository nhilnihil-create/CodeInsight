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

int main() {

    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> h(N);
    rep(i,N) cin >> h[i];

    ll bottom = 1;
    ll top = INF;
    while (bottom < top) {
        ll k = bottom + (top - bottom) / 2;
        ll count = 0;
        rep(i,N) {
            if (h[i] <= k * B) continue;
            count += (h[i] - k * B + (A - B) - 1) / (A - B);
        }
        if (count <= k) top = k;
        else bottom = k + 1;
    }

    cout << bottom << endl;
    
    return 0;
}