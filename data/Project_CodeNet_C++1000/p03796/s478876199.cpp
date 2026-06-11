#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
int mod = 1000000007;
int main() {
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans*=i%mod;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}