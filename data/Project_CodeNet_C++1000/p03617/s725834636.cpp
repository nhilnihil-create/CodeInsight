#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    ll one = min({q*4, h*2, s});

    if (one * 2 <= d) cout << one * n << endl;
    else cout << n/2 * d + n%2 * one << endl;

    return 0;
}
