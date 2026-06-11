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

ll a[55],b[55];
ll c[55], d[55];

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n){
        cin >> a[i] >> b[i];
    }
    rep(i, m){
        cin >> c[i] >> d[i];
    }

    rep(i, n){
        ll tmp = LINF;
        rep(j, m) tmp = min(tmp, abs(a[i]-c[j]) + abs(b[i]-d[j]));
        rep(j, m) {
            if (tmp == abs(a[i]-c[j]) + abs(b[i]-d[j])){
                cout << j+1 << endl;
                break;
            }
        }
    }
    return 0;
}
