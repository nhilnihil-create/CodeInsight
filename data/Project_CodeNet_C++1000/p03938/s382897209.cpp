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

int r[20010], p;
ll a[20010], b[20010];

int main(){
    int n;
    cin >> n;
    rep(i, n) {
        cin >> p;
        r[p]=i+1;
    }

    rep(i, n){
        a[i] = 30000 * (i+1);
        b[i] = 30000 * (n-i-1) + r[i+1];
    }

    rep(i, n) cout << a[i] << " ";
    cout << endl;
    rep(i, n) cout << b[i] << " ";
    cout << endl;

    return 0;
}
