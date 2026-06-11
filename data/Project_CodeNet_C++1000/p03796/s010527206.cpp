#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans *= (i+1);
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}