#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (b < a || n==1 && a!=b) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = (b-a)*(n-1)-(b-a)+1;
    cout << ans << endl;
}