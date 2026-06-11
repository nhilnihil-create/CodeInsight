#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll ans = 0;

    for (ll i = 0; i <= 99; i++){
        if (a <= i && i < b && c <= i && i < d){
            ans++;
        }
    }

    cout << ans << endl;

}