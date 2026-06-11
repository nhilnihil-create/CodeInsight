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

    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    for (ll p = 0; p <= N - 1; p++) {
        ll m = (N - 1) - p;
        ll maximum = A + p * D - m * C;
        ll minimum = A + p * C - m * D;
        if (minimum <= B && B <= maximum) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    
    return 0;
}