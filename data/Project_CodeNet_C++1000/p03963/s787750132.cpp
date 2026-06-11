#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, k;
    cin >> n >> k;
    ll ans = k;
    for(int i = 0; i < n-1; i++){
        ans *= (k-1);
    }
    cout << ans << endl;
    return 0;
}