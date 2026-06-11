#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000000+7;

ll solve(ll x) {
    if (x == 1 || x == 0) {
        return 1;
    } else {
        return solve(x-1)*x % MOD;
    }
}

int main() {
    ll N, M;
    ll ans;
    cin >> N >> M;
    
    if (abs(N-M) >= 2) {
        ans = 0;
    } else if (abs(N-M) == 0){
        ans = solve(N)*solve(M)*2 % MOD;
    } else {
        ans = solve(N)*solve(M) % MOD;
    }

    cout << ans << endl;
}
