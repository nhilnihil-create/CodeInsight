#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int s, k;
    cin >> k >> s;

    ll ans = 0;
    rep(i, k + 1){
        rep(j, k + 1){
            int n = s - (i + j);
            if(n >= 0 && n <= k){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
