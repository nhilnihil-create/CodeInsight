#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    ll a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for(i=0;i<=n-1;i++){
        if(a-b>=-d*i+c*(n-1-i) && a-b<=-c*i+d*(n-1-i)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}