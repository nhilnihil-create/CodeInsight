#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n, k;
    cin >> n >> k;
    ll ans = k;
    rep(i, n-1){
        ans *= k - 1;
    }

    cout << ans << endl;

}