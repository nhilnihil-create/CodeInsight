#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, m;
    cin >> n >> m;
    ll ans = min(n, m / 2);
    ans += (m - ans * 2) / 4;
    cout << ans << endl;
}