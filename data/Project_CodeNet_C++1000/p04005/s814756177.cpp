#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e+18;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = INF;

    ans = min(ans, abs((a/2*2-a)*b*c));
    ans = min(ans, abs(a*(b/2*2-b)*c));
    ans = min(ans, abs(a*b*(c/2*2-c)));
    cout << ans << endl;
    return 0;
}