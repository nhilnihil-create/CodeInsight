#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    ll X;
    cin >> X;
    for(ll ans = 1; ans <= 100000000; ans++) {
        if(ans * (ans + 1) >= 2 * X) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
