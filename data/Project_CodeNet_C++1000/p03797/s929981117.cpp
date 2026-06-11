#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    ll n, m; cin >> n >> m;
    ll ans = 0;
    ans += min(n, m/2);
    ans += (m-2*ans)/4;
    cout << ans;
}
