#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

ll solve(ll x, ll y) {
    if (x == 0 || y == 0) return 0;

    if (x < y && y % x == 0) return (y / x) * x * 2 - x;
    if (y < x && x % y == 0) return (x / y) * y * 2 - y;

    if (x < y){
        return solve(x, y - (y / x) * x) + (y / x) * x * 2;
    }
    else if (x > y){
        return solve(x - (x / y) * y, y) + (x / y) * y * 2;
    }
    else{
        return x;
    }
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N, X;
    cin >> N >> X;
    ll ans = solve(X, N - X) + N;
    cout << ans << endl;
    return 0;
}
